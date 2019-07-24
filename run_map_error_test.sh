#!/bin/bash
#echo on

path=test_files/bad/$1

rm $path.actual.txt

echo test bad	$path
#echo "calling ./bsq $path/$name.txt > $path/$name.actual.txt"

./bsq $path.txt > $path.actual.txt
diff test_files/bad/map_error.expected.txt $path.actual.txt
exit 0
