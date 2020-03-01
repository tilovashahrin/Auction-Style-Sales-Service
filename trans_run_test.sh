#!/bin/bash
for i in ./Test_Files/input/*.inp
do
	filename=${i##*/};
	echo “checking outputs of ${filename%.*}”
	timeout 1 diff ./Test_Files/act_output/${filename%.*}.aop ./Test_Files/tran_output/${filename%.*}.eop
	if [ $? -eq 124 ]; then echo Test Timed Out; fi
	read -p 'Press enter to continue...'
	echo ''
done