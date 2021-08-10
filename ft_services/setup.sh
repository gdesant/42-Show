# !bin/bash

if pidof minikube >/dev/null
then
    minikube delete
fi

minikube start --vm-driver=docker
eval $(minikube -p minikube docker-env)



#EnableMySQl
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml


#CreateMySQLContainer
docker build --no-cache -t mysql_img srcs/mysql/.
docker build --no-cache -t influx_img srcs/influxdb/.
docker build --no-cache -t nginx_img srcs/nginx/.
docker build --no-cache -t ftps_img srcs/ftps/.
docker build --no-cache -t phpmyadmin_img srcs/phpmyadmin/.
docker build --no-cache -t wordpress_img srcs/wordpress/.
docker build --no-cache -t grafana_img srcs/grafana/.

kubectl apply -f srcs/LBConfigMap.yaml
kubectl apply -f srcs/mysql/mysql.yaml
kubectl apply -f srcs/influxdb/influx.yaml
kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f srcs/ftps/ftps.yaml
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f srcs/wordpress/wordpress.yaml
kubectl apply -f srcs/grafana/grafana.yaml


#EnableDashboard
printf "\e[0;32m[Done !]\e[0m\n"
printf "\e[0;32m[dashboard enabled]\e[0m\n"
minikube dashboard &