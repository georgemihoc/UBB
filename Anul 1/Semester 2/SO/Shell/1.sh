#!/bin/bash
max=0
for i in `cat df.fake.rtf | awk '{print $1}'`
do
	a[$i]+=1
done
nr=0
for i in "${a[@]}"
do
	nr+=1
	if [ $i != $max ]
	then
		echo $i $nr
	fi
done
