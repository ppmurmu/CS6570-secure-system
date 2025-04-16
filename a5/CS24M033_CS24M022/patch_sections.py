import random
import string
import os
from pwn import *
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import lief

def random_section_name(length=8):
    return "." + ''.join(random.choices(string.ascii_lowercase, k=length))

def generate_key():
    return ''.join(random.choices(string.ascii_letters + string.digits, k=16)).encode()

def encrypt_section(section_data, key):
    cipher = AES.new(key, AES.MODE_CBC)
    iv = cipher.iv
    padded_data = pad(section_data, AES.block_size)
    encrypted_data = cipher.encrypt(padded_data)
    return iv + encrypted_data

# === Step 1: Encrypt .text section using pwntools ===
binary = ELF("safe_main")

if ".text" in binary.sections:
    key = generate_key()
    print(f"[+] Generated AES key: {key.decode()}")
    
    text_data = binary.get_section_by_name(".text").data()
    encrypted_data = encrypt_section(text_data, key)
    binary.set_section_by_name(".text", encrypted_data)
    print("[+] .text section encrypted.")

# Save to intermediate file so we can perform further modifications using LIEF.
temp_path = "temp_safe_main"
binary.save(temp_path)
print(f"[+] Intermediate binary saved to {temp_path}")

# === Step 2: Rename sections and remove sensitive sections using LIEF ===
lief_binary = lief.parse(temp_path)

# Rename .rodata if it exists.
if lief_binary.has_section(".rodata"):
    rodata = lief_binary.get_section(".rodata")
    new_rodata_name = random_section_name()
    print(f"[+] Renaming .rodata to {new_rodata_name}")
    rodata.name = new_rodata_name

# Rename the (encrypted) .text section.
if lief_binary.has_section(".text"):
    text_section = lief_binary.get_section(".text")
    new_text_name = random_section_name()
    print(f"[+] Renaming .text to {new_text_name}")
    text_section.name = new_text_name

# Remove potentially revealing sections.
sections_to_remove = [".comment", ".symtab", ".strtab", ".debug", ".rela.text", ".note"]
for sec_name in sections_to_remove:
    if lief_binary.has_section(sec_name):
        print(f"[-] Removing section {sec_name}")
        lief_binary.remove_section(sec_name, clear=True)

# === Step 3: Further Obfuscation – Rename all non-critical sections ===
# Define critical sections that are required for proper execution.
critical_sections = [".interp", ".dynamic", ".got", ".plt", ".init", ".fini"]
for sec in lief_binary.sections:
    if sec.name not in critical_sections:
        old_name = sec.name
        new_name = random_section_name()
        sec.name = new_name
        print(f"[+] Renamed section {old_name} to {new_name}")

# === Step 4: Randomize Section Alignments for Extra Obfuscation ===
# For each section that already has a non-zero alignment, assign a new random power-of-2 alignment.
for sec in lief_binary.sections:
    if sec.alignment > 0:
        # Pick a new alignment between 2^6 (64) and 2^12 (4096).
        new_alignment = 2 ** random.randint(6, 12)
        print(f"[+] Changing alignment of section {sec.name} from {sec.alignment} to {new_alignment}")
        sec.alignment = new_alignment
        



# === Final Step: Save the Fully Obfuscated Binary ===
final_path = "safe_main"
lief_binary.write(final_path)
print(f"[+] Final binary saved to {final_path}")

os.remove(temp_path)
print("[*] Cleanup complete.")
