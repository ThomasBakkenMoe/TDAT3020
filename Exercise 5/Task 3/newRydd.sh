#!/bin/bash
dir="$(cd $(dirname "$0"); pwd)"
 find ./home -type d -name "jpg" -prune -o -name "*.jpg" -exec ls {} \; -exec "$dir"/flyttjpg.sh {} \;
