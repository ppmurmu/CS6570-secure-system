#!/usr/bin/env python3
import random

# How many dummy pairs to generate
N = 30

# Pick N unique 4‑digit IDs between 1000 and 9999
ids = random.sample(range(1000, 10000), N)

with open("dummy_funcs.c", "w") as f:
    f.write("// Auto‑generated dummy functions\n")
    f.write("#include <stddef.h>\n#include <stdint.h>\n\n")

    for idx in ids:
        # key_XXXX signature
        f.write(f"__attribute__((used)) static void key_{idx}(\n")
        f.write("    const uint8_t *obf,\n")
        f.write("    uint8_t *out,\n")
        f.write("    size_t len,\n")
        f.write("    uint8_t mask)\n")
        f.write("{\n")
        f.write("    // dummy XOR loop\n")
        f.write("    for (size_t i = 0; i < len; i++) {\n")
        f.write("        out[i] = obf[i] ^ mask;\n")
        f.write("    }\n")
        f.write("}\n\n")

        # egg_XXXX signature
        f.write(f"__attribute__((used)) static void egg_{idx}(void)\n")
        f.write("{\n")
        f.write("    // dummy work to confuse decompiler\n")
        f.write("    volatile int x = 0;\n")
        f.write("    for (int i = 0; i < 64; i++) {\n")
        f.write("        x += (i * 7) ^ 0x5F;\n")
        f.write("    }\n")
        f.write("}\n\n")

    # Optionally, generate a function‑pointer table to force calls
    f.write("// Optional: a table of pointers to all dummy funcs\n")
    f.write("typedef void (*func_t)(void);\n")
    f.write("func_t dummy_table[] = {\n")
    for idx in ids:
        f.write(f"    (func_t)key_{idx},\n")
        f.write(f"    egg_{idx},\n")
    f.write("};\n")
