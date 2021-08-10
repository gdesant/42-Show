FROM alpine:latest

RUN apk update \
&& apk add vsftpd  openssl telegraf && apk add --no-cache --upgrade bash \
&& rm -rf /var/cache/apk/*

RUN { echo "password_ftp"; echo "password_ftp"; } | adduser user_ftp

RUN mkdir -p /srv/ftp
RUN mkdir -p /etc/telegraf
RUN mkdir -p /run/openssl
RUN mkdir -p /run/telegraf
RUN mkdir -p /run/vsftpd

COPY ./scripts/telegraf.conf /etc/telegraf/
COPY ./scripts/vsftpd.conf /etc/vsftpd/
COPY ./scripts/liveprobe.sh /home/script/liveprobe.sh

RUN openssl req -newkey rsa:2048 -x509 -sha256 -days 365 -nodes -out /etc/ssl/localhost.crt -keyout /etc/ssl/localhost.key -subj "/C=FR/ST=Paris/L=Paris/O=42/CN=localhost"

RUN echo "Temp file for ano_user." > /srv/ftp/file.txt
RUN echo "Temp file for user_ftp." > /home/user_ftp/file.txt

#StartScript
COPY ./scripts/ftps-config.sh /home/script/start_ftps.sh
RUN chmod +x /home/script/start_ftps.sh /home/script/liveprobe.sh
CMD ./home/script/start_ftps.sh

EXPOSE 21 
EXPOSE 4242