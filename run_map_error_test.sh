#!/bin/bash
#echo on

path=test_files/bad/$1
name=$2
rm $path/$name.actual.txt

echo test bad	$1 $name
#echo "calling ./bsq $path/$name.txt > $path/$name.actual.txt"

./bsq $path/$name.txt > $path/$name.actual.txt
diff test_files/bad/map_error.expected.txt $path/$name.actual.txt
exit 0
