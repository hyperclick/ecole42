#!/bin/bash

echo "

------- tests ---------


"



#./run_test.sh good example\ file\ with\ spaces
echo pipe
rm test_files/good/two_lines.from_pipe.actual.txt
cat test_files/good/two_lines.txt | ./bsq > test_files/good/two_lines.from_pipe.actual.txt
diff test_files/good/two_lines.expected.txt test_files/good/two_lines.from_pipe.actual.txt

#./run_test.sh good number_is_less_than_rows
#./run_test.sh good zero_len
./run_map_error_test.sh header  number_is_less_than_rows
./run_map_error_test.sh header  zero_len


./run_test.sh good one_cell_obstacle
./run_test.sh good one_cell_free
./run_test.sh good one_line_all_free
./run_test.sh good one_line_all_three_free
./run_test.sh good one_line_all_two_free
./run_test.sh good one_line_one_obstacle_at_2
./run_test.sh good one_line_one_obstacle_at_BOL
./run_test.sh good one_line_one_obstacle_at_EOL
./run_test.sh good thismapisValid
./run_test.sh good thismapisValid2
./run_test.sh good three_lines_all_free
./run_test.sh good two_lines_all_free
./run_test.sh good two_lines
./run_test.sh good twosolutionsbutValid
./run_test.sh good nosolutionMapIsFull
./run_test.sh good example_file
./run_test.sh good all_numbers


./run_map_error_test.sh header/1char
./run_map_error_test.sh header/2char
./run_map_error_test.sh header/3char
./run_map_error_test.sh header/4char
./run_map_error_test.sh header/same_char
./run_map_error_test.sh header/first_is_NAN
./run_map_error_test.sh header/one_digit
./run_map_error_test.sh header/no_new_line
./run_map_error_test.sh header/empty_file

./run_map_error_test.sh header/len_is_negative
./run_map_error_test.sh header/number_is_greater_than_rows

./run_map_error_test.sh empty_map
./run_map_error_test.sh extra_char_on_map
./run_map_error_test.sh not_equal_lines.txt


exit 0

./run_map_error_test.sh
./run_map_error_test.sh
./run_map_error_test.sh
./run_map_error_test.sh
./run_map_error_test.sh header
./run_map_error_test.sh header
./run_map_error_test.sh header


./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad
./run_test.sh bad

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good

./run_test.sh good




