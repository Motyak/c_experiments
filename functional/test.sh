#!/usr/bin/env bash

set -o errexit

for program in reduce filter map pipe; do
    echo $'\n'"${program}.."

    diff --text --color=always \
        <("./${program}" | tee /dev/fd/2) \
        <(sed -rn 's/^.*printf\(.*\); \/\/ (.*)$/\1/gmp' < "${program}.c")

    echo "OK"
done
