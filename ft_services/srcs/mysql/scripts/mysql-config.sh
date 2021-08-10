/usr/bin/mysql_install_db --user=root --datadir="/var/lib/mysql"
/usr/bin/mysqld_safe --datadir="/var/lib/mysql" --no-watch

until mysql
do
    clear
    echo "WaitForMySQL ..."
done

if ! mysql -u root -e 'use wordpress'; then
        mysql -u root --skip-password -e "CREATE DATABASE wordpress;"
        mysql -u root --skip-password -e "CREATE USER IF NOT EXISTS 'user'@'%' IDENTIFIED BY 'password';"
        mysql -u root --skip-password -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'user'@'%' WITH GRANT OPTION;"
        mysql -u root --skip-password -e "FLUSH PRIVILEGES;"
        mysql -u root --skip-password wordpress < /wordpress.sql
fi

telegraf --config /etc/telegraf/telegraf.conf &
tail -f /dev/null