#!/bin/bash

ls -la
#ejecutable chmod +x scheduler_discovery.sh

echo trololo

#kernel
echo "Los headers del kernel estan en /usr/src y l aversion de kernel de ubuntu 22.64 es:"
uname -r
echo

#hacer el install de el source de linux desde terminal para revisar sus contenidos descomprimiendo el kernel
echo "se instala de la siguinete manera"
sudo apt install linux-source
echo
#entrar en el directorio de source
echo "de la siguiente manera"
cd linux-source-5.15.0
echo
#buscar los directorios dentro del source

#entrar al directorio del kernel
echo
cd kernel/
echo

#buscar el archivo que contenga el scheduler, en este caso es "sched"
echo
cd sched/
echo

#una vez dentro del directorio hay que entrar al mismo y ver el codigo
echo "utilizando el siguiente comando"
cat sched.h
echo