#!/bin/bash

# Testing script for CPP01 ex04

echo -e "\n---------- MAKING TESTS ----------\n"

PROGRAM="./Sed_is_for_losers"

chmod -r ./tests/non_readable_file

echo -e "--- Non-existing file ---"
$PROGRAM foo a b
echo
echo

echo -e "--- Non_readable_file ---"
$PROGRAM ./tests/not_readable_file a b
echo
echo

echo -e "--- Empty_file ---"
$PROGRAM ./tests/empty_file a b
echo
echo

echo -e "--- Replacing all spaces by '#' in file1 ---"
$PROGRAM ./tests/file1 " " "#"
diff --color ./tests/file1 ./tests/file1.replace
rm ./tests/file1.replace
echo
echo

echo -e "--- Replacing '44' by '42' in file2 ---"
$PROGRAM ./tests/file2 "44" "42"
diff --color ./tests/file2 ./tests/file2.replace
rm ./tests/file2.replace
echo
echo

echo -e "--- Replacing 'gatti' by 'cuccioli' in file3 ---"
$PROGRAM ./tests/file3 "gatti" "cuccioli"
diff --color ./tests/file3 ./tests/file3.replace
rm ./tests/file3.replace
echo
echo

echo -e "--- Replacing '4' by nothing in file4 ---"
$PROGRAM ./tests/file4 "4" ""
diff --color ./tests/file4 ./tests/file4.replace
rm ./tests/file4.replace
echo
echo

echo -e "--- Replacing nothing with something in file5 ---"
$PROGRAM ./tests/file5 "" "something"
echo
echo

echo -e "--- Replacing 'gatti in fila' by 'mici in coda batuffolosa' in file_with_blank_lines ---"
$PROGRAM ./tests/file_with_blank_lines "gatti in fila" "mici in coda batuffolosa"
diff --color ./tests/file_with_blank_lines ./tests/file_with_blank_lines.replace
rm ./tests/file_with_blank_lines.replace
echo

chmod +r ./tests/non_readable_file

echo -e "----------------------------------\n"