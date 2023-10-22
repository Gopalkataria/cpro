#!/usr/bin/bash

TIMELIMIT=1

echo $1 $2 $3 $4


gcc -Wall $1 -o $2  -lm
echo "" > /tmp/cproutput2
echo "Debug: executing with $TIMELIMIT second(s) time limit .."
timeout $TIMELIMIT $2 < $3  > /tmp/cproutput || echo "SEG fault or TLE $TIMELIMIT second(s) limit" > /tmp/cproutput2
# /usr/bin/time -o $4 timeout 1 $2 < $3  > /tmp/cproutput || echo "TLE" > /tmp/cproutput
head -500 /tmp/cproutput > $4
more /tmp/cproutput2 >> $4
echo $(date) >> $4
echo "Task finished."
rm /tmp/cproutput
