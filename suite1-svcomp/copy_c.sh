#!/bin/bash
#set -x
root="/home/rjf/Projects/cav23/bench-defs/sv-benchmarks/c/"
for x in `cat files.txt`; do
	folder=`echo $x | tr "/" " " | awk '{print $1;}'`
	ymlfile=`echo $x | tr "/" " " | awk '{print $2;}'`
	file=`echo $ymlfile | sed s/\.yml/\.c/g`
	mkdir -p $folder
	cp $root/$folder/$file ./$folder/$file
	echo "CP "$root"/"$folder"/"$file"  ->  ./"$folder"/"$file
done
