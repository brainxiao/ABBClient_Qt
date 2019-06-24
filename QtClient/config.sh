#!/bin/bash

if [ -d ~/share ]
then
	echo "~/share has exist"
else
	mkdir ~/share
	chmod 777 ~/share
fi
echo "your shareDir IP: " $1
sudo mount -t cifs -o username=Administrator,password=000,file_mode=0777,dir_mode=0777,vers=2.1 //$1/ShareDir /home/brain/share/
