#!/usr/bin/bash

gcc -Wall $1 -o $2

timeout 1 $2 < $3 > /tmp/cproutput || echo "TLE" > /tmp/cproutput
mv /tmp/cproutput $4
