#!/bin/bash
# server.sh -- http://localhost:9000/hello?world

RESP=/tmp/webresp
[ -p $RESP ] || mkfifo $RESP

while true ; do
( cat $RESP ) | nc -l 9000 | (
REQ=`./a.out $(head -1)`
echo "[`date '+%Y-%m-%d %H:%M:%S'`] $REQ" | head -1
cat >$RESP <<EOF
$REQ
EOF
)
done

