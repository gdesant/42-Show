FROM alpine:latest

#InstallPackage
RUN apk update && apk upgrade && apk add bash \
&& apk add openssl telegraf nginx \
&& apk add wget php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session --no-cache

# installing phpmyadmin
RUN mkdir -p /www/ \
&& wget https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.tar.gz
RUN tar xzf phpMyAdmin-4.9.2-all-languages.tar.gz -C /www/
RUN mv /www/phpMyAdmin-4.9.2-all-languages /www/phpmyadmin \
&& rm phpMyAdmin-4.9.2-all-languages.tar.gz

RUN mkdir /etc/nginx/ssl
RUN mkdir /etc/telegraf
RUN mkdir -p /run/nginx

COPY ./scripts/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./scripts/telegraf.conf /etc/telegraf/
COPY ./scripts/config.inc.php /www/phpmyadmin/config.inc.php
COPY ./scripts/liveprobe.sh /home/script/liveprobe.sh

RUN openssl req -newkey rsa:2048 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.crt -keyout /etc/nginx/ssl/localhost.key -subj "/C=FR/ST=Paris/L=Paris/O=42/CN=ft_services"

# StartScript
COPY ./scripts/phpmyadmin-config.sh /home/script/start_pma.sh
RUN chmod +x /home/script/start_pma.sh /home/script/liveprobe.sh
ENTRYPOINT ./home/script/start_pma.sh

EXPOSE 5000
