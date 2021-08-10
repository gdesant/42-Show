#!/bin/ash
ps > health.tmp

cat health.tmp | grep "vsftpd" > /dev/null 2>&1
ret=$?

cat health.tmp | grep "telegraf" > /dev/null 2>&1
ret2=$?

if [ $ret -ne 0 ] || [ $ret2 -ne 0 ]
then
	return 1
else
	return 0
fi
