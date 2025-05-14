from Crypto.PublicKey import RSA


f = open('Pubkey.pem', 'rb')
key = RSA.importKey(f.read())


# get n,e
n = key.n
e = key.e

import hashlib

def compute_file_hash(file_path, algorithm='sha256'):
    """Compute the hash of a file using the specified algorithm."""
    hash_func = hashlib.new(algorithm)
    with open(file_path, 'rb') as file:
        while chunk := file.read(8192):  # Read in 8KB chunks
            hash_func.update(chunk)
    return int(hash_func.hexdigest(),16)

current_hash = compute_file_hash("main")
current_hash = current_hash % n
current_hash = current_hash * compute_file_hash("allowed")
current_hash = current_hash % n
current_hash = current_hash * compute_file_hash("not_allowed")
current_hash = current_hash % n


with open("signature", "r") as f:
    signature = int(f.read().strip())
# decrypt using public key to get original digest
digest = pow(signature, e, n)


if digest == current_hash:
    print("Signature is valid")
    import os
    os.system("chmod +x main")
    os.system("./main")
else:
    print("Signature is invalid")
