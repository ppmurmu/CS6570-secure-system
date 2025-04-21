import subprocess
import re

# Load plaintexts from test_results.txt
plaintexts = []
with open("test_results.txt", "r") as f:
    for line in f:
        match = re.match(r"Plaintext:\s*(\S+)", line)
        if match:
            plaintexts.append(match.group(1))

# Run a.out for each plaintext
for pt in plaintexts:
    print(f"\n=== Running for Plaintext: {pt} ===")
    result = subprocess.run(["./a.out", pt], capture_output=True, text=True)
    print(result.stdout)
