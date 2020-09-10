#!/bin/bash

echo "Decompressing files!"
cd home
find ./* -name "*.zip" -o -name "*.gz" -exec ls {} \; -exec gzip -d {} \; 