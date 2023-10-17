#!/usr/bin/bash

gcc -Wall $1 -o $2

$2 < $3 > $4