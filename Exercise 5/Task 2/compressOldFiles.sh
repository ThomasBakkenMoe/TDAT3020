#!/bin/bash

#Compresses files that have not been modified for a week in the home folder (a sub-folder of the folder where the script recides).
echo "Compressing old files!"
cd home
find ./* -type f -mtime +7 -size +9k -not -name "*.zip" -not -name "*.gz" -exec ls {} \; -exec gzip {} \;  