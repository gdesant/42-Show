FROM alpine:latest

RUN apk update && apk upgrade && apk add bash \
&& apk add nginx telegraf openssl 

COPY site /www

RUN mkdir /etc/nginx/ssl
RUN mkdir /etc/telegraf
RUN mkdir -p /run/telegraf
RUN mkdir -p /run/nginx
RUN mkdir -p /run/openssl

COPY ./scripts/nginx.conf /etc/nginx/
COPY ./scripts/telegraf.conf /etc/telegraf/
COPY ./scripts/liveprobe.sh /home/script/liveprobe.sh

RUN openssl req -newkey rsa:2048 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.crt -keyout /etc/nginx/ssl/localhost.key -subj "/C=FR/ST=Paris/L=Paris/O=42/CN=ft_services"

#StartScript
COPY ./scripts/nginx-config.sh /home/script/start_ng.sh
RUN chmod +x /home/script/start_ng.sh /home/script/liveprobe.sh
CMD ./home/script/start_ng.sh

EXPOSE 80
EXPOSE 443

