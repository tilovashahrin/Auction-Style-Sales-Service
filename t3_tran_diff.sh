#!/bin/bash
for i in ./Test_Files/tran_output/*.top
do
	DB=./SQA_FrontEnd/SQA_FrontEnd/DataFiles; filename=${i##*/};
	echo “checking tansaction outputs of ${filename%.*}”
	./SQA_FrontEnd/SQA_FrontEnd/a.out $DB/UserDB.txt $DB/ItemDB.txt ./Test_Files/tran_output/${filename%.*}.atf <./Test_Files/input/${filename%.*}.inp > ./Test_Files/act_output/${filename%.*}.aop
	timeout 1 diff  ./Test_Files/tran_output/${filename%.*}.top ./Test_Files/tran_output/${filename%.*}.atf
	if [ $? -eq 124 ]; then echo Test Timed Out; fi
	read -p 'Press enter to continue...'
	echo ''
done
