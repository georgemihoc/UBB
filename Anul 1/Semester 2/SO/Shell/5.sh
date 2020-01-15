#!/bin/bash
for i in `ls | awk '{print $1}'`
do
	echo `cksum`
done
