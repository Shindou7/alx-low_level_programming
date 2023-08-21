#!/bin/bash
wget -P .. https://raw.githubusercontent.com/Shindou7/alx-low_level_programming/master/0x18-dynamic_libraries/shin2.so
export LD_PRELOAD="$PWD/../shin2.so"
