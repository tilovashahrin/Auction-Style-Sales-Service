#!/bin/bash
for i in ./Test_Files/input/*.inp
do
	DB=./SQA_FrontEnd/SQA_FrontEnd/DataFiles; filename=${i##*/};
	echo “running test ${filename%.*}”
	timeout 1 ./SQA_FrontEnd/SQA_FrontEnd/a.out $DB/UserDB.txt $DB/ItemDB.txt $DB/Transout.atf < $i > ./Test_Files/act_output/${filename%.*}.aop
	if [ $? -eq 124 ]; then echo Test Timed Out; fi
done