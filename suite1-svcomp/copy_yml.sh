#!/bin/bash
#set -x
root="/home/rjf/Projects/cav23/bench-defs/sv-benchmarks/c/"
for x in `cat files.txt`; do
	folder=`echo $x | tr "/" " " | awk '{print $1;}'`
	file=`echo $x | tr "/" " " | awk '{print $2;}'`
	#echo "folder: "$folder" ; file: "$file
	mkdir -p $folder
	cp $root/$x ./$folder/$file
	echo "CP "$root"/"$x"  ->  ./"$folder"/"$file
done
