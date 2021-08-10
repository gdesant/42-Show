FROM alpine:latest

RUN apk update \
&& apk add mariadb openrc mariadb-client telegraf && apk add --no-cache --upgrade bash \
&& rm -rf /var/cache/apk/*

RUN mkdir -p /etc/telegraf
RUN mkdir -p /run/telegraf
RUN mkdir -p /run/openrc

COPY ./scripts/telegraf.conf /etc/telegraf/
COPY ./scripts/wordpress.sql .
COPY ./scripts/liveprobe.sh /home/script/liveprobe.sh

#StartScript
COPY ./scripts/mysql-config.sh /home/script/start_msql.sh
RUN chmod +x /home/script/start_msql.sh /home/script/liveprobe.sh
CMD ./home/script/start_msql.sh

EXPOSE 3306
