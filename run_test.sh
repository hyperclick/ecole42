#!/bin/bash
echo "TestScript1 Arguments:"
echo "$1"
echo "$2"
echo "$# params called"
path="test_files/good"
echo path = "$path"
./bsq $path/$1.txt #> test_files/good/$1.actual.txt
diff test_files/good/one_cell_obstacle.expected.txt test_files/good/one_cell_obstacle.actual.txt
exit 1
