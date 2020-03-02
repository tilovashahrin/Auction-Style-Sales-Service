#!/bin/bash
for i in ./Test_Files/input/*.inp
do
	filename=${i##*/};
	echo "checking outputs of ${filename%.*}"
	timeout 1 diff ./Test_Files/exp_output/${filename%.*}.eop ./Test_Files/act_output/${filename%.*}.aop
	if [ $? -eq 124 ]; then echo Test Timed Out; fi
	read -p 'Press enter to continue...'
	echo ''
done
