#!/bin/bash

dir=$1

if [[ "$dir" == "" ]]; then
    dir="."
fi

find $dir -type f -name "*.cpp" | while read -r line
do
    clang-format -i $line
done

