#!/bin/bash

progname=$(basename $0)

dir=$1
if [[ "$dir" == "" ]]; then
    dir="."
fi

find $dir -type d -name "*" -not -path "*/.git*" | grep -E "[a-zA-Z]{3}[0-9]+" | while read -r line; do
    if [[ ${line} =~ (([a-z]+)([0-9]+)) ]]; then
        contest=${BASH_REMATCH[1]}
        contestType=${BASH_REMATCH[2]}
        contestNo=${BASH_REMATCH[3]}

        contestName=""
        if [[ "$contestType" == "abc" ]]; then
            contestName="Atcoder Beginner Contest"
        elif [[ "$contestType" == "arc" ]]; then
            contestName="Atcoder Regular Contest"
        fi

        readme="$contest/README.md"
        cat > $readme <<EOS
# $contestName $contestNo

https://atcoder.jp/contests/$contest

EOS
        find $contest/* -type d | while read -r problem; do
            statusFile="$problem/status"
            if [[ $problem =~ [a-zA-Z]+[0-9]+/([a-z]+) ]]; then
                problemNo=${BASH_REMATCH[1]}
                problemNoUpper=$(echo $problemNo | tr "[:lower:]" "[:upper:]")

                accepted=" "
                if [[ -e $statusFile && $(cat $statusFile) == "AC" ]]; then
                    accepted="x"
                fi
                echo "- [$accepted] [${problemNoUpper}](https://atcoder.jp/contests/$contest/tasks/${contest}_${problemNo})" >> $readme
            fi
        done

        echo >> $readme
        echo >> $readme
        echo "Code generated by ${progname}; DO NOT EDIT." >> $readme
    fi
done

