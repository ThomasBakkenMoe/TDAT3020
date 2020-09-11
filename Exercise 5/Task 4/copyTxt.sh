#!/bin/bash

echo "Finding .txt files and copying them!"
cd home
find ./* -type f -name "*.txt" -exec cp {} {}.kopi \;