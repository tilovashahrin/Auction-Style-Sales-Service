#! /bin/bash

for i in ./Test_Files/input/*
do
	filename=${i##*/};
	echo "running test $i"
		./SQA_FrontEnd/SQA_FrontEnd/a.out <$i> ./Test_Files/act_output/${filename%.*}.aop
done 