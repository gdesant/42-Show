/usr/bin/telegraf &
/usr/sbin/grafana-server --homepath=/usr/share/grafana --config=/etc/grafana.ini
tail -F /dev/null