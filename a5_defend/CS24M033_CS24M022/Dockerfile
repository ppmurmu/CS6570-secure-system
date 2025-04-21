

FROM ubuntu:22.04

# Install build tools, binutils, Python, and pip
RUN apt-get update && apt-get install -y \
    build-essential \
    binutils \
    python3 \
    python3-pip \
    && apt-get clean

# Install LIEF for ELF manipulation
RUN pip3 install lief

RUN pip3 install lief keystone-engine

RUN pip3 install pycryptodome


RUN pip3 install pwn


# Set internal build directory
WORKDIR /app

# Copy your source files and patching script
COPY main.c .
COPY patch_sections.py .

# Compile the binary
RUN gcc -static -O2 -o safe_main main.c

# Patch the binary (rename sections and remove unwanted sections)
RUN python3 patch_sections.py

# Strip debug symbols
RUN strip safe_main



# Create an output directory (this folder will be mapped to the host)
RUN mkdir -p /output && cp safe_main /output/safe_main

# Set working directory to /output so that the final binary is there
WORKDIR /output
# At container startup, update safe_main from /app to /output, then run the binary
# with the time command (using -v for verbose output) to display detailed timing info.
CMD sh -c "cp /app/safe_main /output/safe_main && echo 'Safe binary copied to host directory'; /app/safe_main abcdefghijklmnopq"

