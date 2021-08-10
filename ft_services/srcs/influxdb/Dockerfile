FROM alpine:latest

RUN apk update \
&& apk add influxdb telegraf && apk add --no-cache --upgrade bash \
&& rm -rf /var/cache/apk/*

RUN mkdir -p /etc/telegraf
RUN mkdir -p /run/telegraf
RUN mkdir -p /run/influxdb
RUN mkdir -p /var/lib/influxdb

RUN chmod 777 /var/lib/influxdb

COPY ./scripts/telegraf.conf /etc/telegraf/
COPY ./scripts/liveprobe.sh /home/script/liveprobe.sh

#StartScript
COPY ./scripts/influx-config.sh /home/script/start_influx.sh
RUN chmod +x /home/script/start_influx.sh /home/script/liveprobe.sh
CMD ./home/script/start_influx.sh

EXPOSE 8086