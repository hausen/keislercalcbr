#!/bin/bash
i=0
prefix=tmp
dir=`dirname $0`
while read -r line
do
  let i=$i+1
  file=`printf "$prefix%03d.svg" $i`
  opts=""
  echo "$line" | grep '^{' -q
  if [ $? == 0 ]
  then
    opts="-n"
  fi
  echo "$line" | "$dir/latextosvg.sh" $opts $* > $file
done
