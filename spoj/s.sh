for (( i = 0; ; i++ )); do
	echo $i
	./gen
	./test < in > test_out
	./brute < in > brute_out
	diff -w test_out brute_out || break
done