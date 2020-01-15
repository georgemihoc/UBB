#!/bin/bash
nr=0
nr2=1
for i in `cat text.txt`
do
	if [ $nr == $nr2 ]
	then
		a+=,
	fi	
	nr=1
	a+=$i@scs.ubbcluj.ro	
done
echo $a
