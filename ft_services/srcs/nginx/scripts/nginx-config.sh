nginx -g "daemon off;" &
telegraf --config /etc/telegraf/telegraf.conf &
tail -f /dev/null