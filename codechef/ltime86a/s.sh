for (( i = 0; ; i++ )); do
	echo $i
	./gen > in
	./test < in > out1
	python brute.py < in > out2
	diff -w out1 out2 || break
done