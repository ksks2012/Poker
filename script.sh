#!/bin/bash

make clean all

#@echo "1  test code"
#@echo "    1  deck_TEST"
#@echo "    2  ownCard_TEST"
#@echo "    3  range_TEST"
#@echo "    4  tempCard_TEST"
#@echo "2  Number of player"


#gdb --args ./poker.out 4 2
./poker.out 4 2
