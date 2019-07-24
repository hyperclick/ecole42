#!/bin/bash
./bsq test_files/good/one_cell_obstacle.txt > test_files/good/one_cell_obstacle.actual.txt
diff test_files/good/one_cell_obstacle.expected.txt test_files/good/one_cell_obstacle.actual.txt
