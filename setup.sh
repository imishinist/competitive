#!/bin/bash

PROGNAME="$(basename $0)"
contest=$1

usage() {
    echo "Usage: $PROGNAME contest_name"
}

if [ "$contest" == "" ]; then
    usage
    exit 1
fi

echo $contest

for i in a b c d e f; do
    dir=$contest/$i
    mkdir -p $dir
    [[ ! -e $dir/main.cpp ]] && cp boilerplate/main.cpp $dir/main.cpp

    cat > $dir/runtest <<'EOS'
#!/bin/bash

set -e

runtest() {
    ./a.out < "$1" > result
    if [ "$(cat result)" != "$(cat $2)" ]; then
        echo "$1: $(cat $2) expected, but got $(cat result)"
        exit 1
    fi
    echo "test case #$1 => $(cat result)"
}

clang++ -Wall -O2 main.cpp

EOS

    for j in 1 2 3; do
        touch $dir/input$j
        touch $dir/output$j

        cat >> $dir/runtest <<EOS
runtest input$j output$j
EOS
    done

    cat >> $dir/runtest <<EOS
echo "OK"
EOS
    chmod +x $dir/runtest
done
