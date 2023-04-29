#!/usr/bin/env bash

TTY=/dev/$(ps -p $$ | tail -n1 | awk '{print $2}')

function print_separator {
    local separator_char=${1:-"="}

    local term_width=$(stty -a --file=$TTY | grep -Po '(?<=columns )\d+')
    printf "$separator_char%.0s" $(seq $term_width)
}

input=$(cat)
sep=$(print_separator)

echo "${input//$'\r\n'/$sep}"
