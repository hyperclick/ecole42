#!/bin/bash
#echo on

path=test_files/$1
name=$2
rm $path/$name.actual.txt

echo test	$1 $name
#echo "calling ./bsq $path/$name.txt > $path/$name.actual.txt"

./bsq $path/$name.txt > $path/$name.actual.txt
diff $path/$name.expected.txt $path/$name.actual.txt
exit 0
