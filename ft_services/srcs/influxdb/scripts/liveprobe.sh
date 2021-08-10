#!/bin/ash

ps > health.tmp

cat health.tmp | grep "influxd" > /dev/null 2>&1
ret=$?

influx -execute "SHOW DATABASES;" > db.tmp
cat db.tmp | grep "grafana" > /dev/null 2>&1
ret2=$?

cat health.tmp | grep "telegraf" > /dev/null 2>&1
ret3=$?

if [ $ret -ne 0 ] || [ $ret2 -ne 0 ] || [ $ret3 -ne 0 ]
then
	return 1
else
	return 0
fi
