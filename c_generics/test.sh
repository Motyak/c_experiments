#!/usr/bin/env bash

#             output ----           ---- expected
#                        v         v
diff --color=always <(./a.out) <(sed -rn 's/^.*printf\(.*\); \/\/ (.*)$/\1/gmp' < c.c) && echo "OK"
