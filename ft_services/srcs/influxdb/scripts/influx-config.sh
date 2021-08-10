sed -i 's/# auth-enabled = false/auth-enabled = true/g' /etc/influxdb.conf
influxd run &
sleep 5

influx -execute "SHOW DATABASES;" > status.tmp
cat status.tmp | grep "grafana" > /dev/null 2>&1
ret=$?

if [ $ret -ne 0 ]; then
	influx -execute "CREATE USER graf_user WITH PASSWORD 'password' WITH ALL PRIVILEGES"
    influx -username 'graf_user' -password 'password' -execute "CREATE DATABASE grafana"
    influx -username 'graf_user' -password 'password' -execute "CREATE RETENTION POLICY ftservices ON grafana DURATION 1h REPLICATION 1 DEFAULT"
fi

telegraf --config /etc/telegraf/telegraf.conf &
tail -f /dev/null