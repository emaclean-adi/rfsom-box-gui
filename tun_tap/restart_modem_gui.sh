#!/bin/sh

ip=$(cat /tmp/modem-ip)
subnet=$(cat /tmp/modem-subnet)
delay=$(cat /tmp/modem-delay)
echo $ip
echo $subnet
echo $delay
restart_modem.sh $ip $subnet $delay

