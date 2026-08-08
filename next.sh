#!/bin/bash
date=$(date '+%Y%m%d')
num=1

while [ -f "$date-$num.cpp" ]
do
    let num++
done

cat temp.cpp > "${date}-${num}.cpp"
printf "Created: ${date}-${num}.cpp\n"