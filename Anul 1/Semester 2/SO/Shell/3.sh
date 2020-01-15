#!/bin/bash
cat df.fake.rtf |sed s/%//g |awk '{if($3+$4<=1024 && $3+$4!=0 || $8>90 && $8!="iused")print $6}'
