#!/bin/bash
i=0
prefix=tmp
dir=`dirname $0`
while read -r line
do
  let i=$i+1
  file=`printf "$prefix%03d.svg" $i`
  echo "$line" | "$dir/latextosvg.sh" > $file
done
