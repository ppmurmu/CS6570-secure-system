key = [0xb7, 0x23, 0x89, 0x43, 0x35, 0x68, 0x3d, 0xcb, 0xcc, 0x6f, 0xd0, 0x8d, 0x7e, 0x7c, 0x9b, 0xf2]
xor_mask = 0xAA
obf = [hex(b ^ xor_mask) for b in key]
print(", ".join(obf))

#here we are XOR masking with 0xAA
# encrypt_egg_params.py
egg_params = [
    1, 4, 3, 0, 1, 0,
    3, 2, 3, 2, 0, 3,
    4, 3, 0, 0, 0, 2,
    7, 1, 0, 1, 2, 2,
    9, 3, 0, 0, 1, 1
]

xor_key = 0x7C
enc = [hex(b ^ xor_key) for b in egg_params]
print(", ".join(enc))
