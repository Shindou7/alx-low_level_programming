#!/bin/bash
wget -qP /tmp/ https://github.com/Shindou7/alx-low_level_programming/raw/master/0x18-dynamic_libraries/shin2.so
export LD_PRELOAD="/tmp/shin2.so"
