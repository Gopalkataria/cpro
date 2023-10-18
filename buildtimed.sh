#!/usr/bin/bash

TIMELIMIT=5

echo $1 $2 $3 $4

gcc -Wall $1 -o $2
echo "" > /tmp/cproutput3
timeout $TIMELIMIT $2 < $3  > /tmp/cproutput || echo "TLE $TIMELIMIT second(s) limit " >> /tmp/cproutput3
echo "Debug: Checking with 15 sec lim .."
/usr/bin/time -o /tmp/cproutputime  timeout 15 $2 < $3  >> /dev/null
head -100  /tmp/cproutput > $4
more /tmp/cproutput3 >> $4
more /tmp/cproutputime >> $4
echo "Task finished."

rm /tmp/cproutput