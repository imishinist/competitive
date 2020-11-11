#!/bin/bash

contest=$1
problem=$2

dir=$contest/$problem

for i in input1 output1 input2 output2 input3 output3; do
    read -r -p "run: pbpaste > $i. ok?[Y/n]" IN
    case "$IN" in
        [yY]*)
            ;;
        [nN]*)
            break
            ;;
        *)
    esac
    pbpaste > $dir/$i
done

