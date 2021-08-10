FROM alpine:latest

RUN apk update \
&& apk add telegraf grafana=7.3.6-r0 --no-cache

RUN mkdir -p /etc/telegraf
RUN mkdir -p /run/telegraf

COPY ./scripts/telegraf.conf /etc/telegraf/
COPY ./scripts/config.ini /etc/grafana.ini
COPY ./scripts/config.yaml /usr/share/grafana/conf/provisioning/datasources/
COPY ./scripts/liveprobe.sh /home/script/

COPY /dashboards /usr/share/grafana/conf/provisioning/dashboards/

COPY ./scripts/grafana-config.sh /home/script/start_gf.sh
RUN chmod +x /home/script/start_gf.sh /home/script/liveprobe.sh
CMD ./home/script/start_gf.sh

EXPOSE 3000