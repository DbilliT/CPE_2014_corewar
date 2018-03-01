#!/bin/bash

GREEN="\\033[1;32m"
RED="\\033[1;31m"
NORMAL="\\033[0;39m"

officialASM=$1
persoASM=$2
sfile=$3
corfile=$4
my_core="check.cor"

if [ "$#" -ne 4 ]
then
    echo -e $RED "Usage : /asm_diff official_binary binary .s .cor" $NORMAL
    exit 0
fi

my_res=$(./$persoASM $sfile)
mv $corfile check.cor
official_res=$(./$officialASM $sfile)
diff $my_core $corfile >> check.log
if [ "$?" != 0 ]
then
    echo -e $RED "Output differ" $NORMAL
    exit 0
else
    echo -e $GREEN "Match" $NORMAL
fi
