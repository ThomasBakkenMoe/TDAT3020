#!/bin/bash
dir="$(cd $(dirname "$0"); pwd)"
 find ./home -name "*.jpg" -exec "$dir"/flyttjpg.sh {} \;
