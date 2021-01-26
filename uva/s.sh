for (( i = 0; ; i++ )); do
	echo Test $i
	./gen > in
	./sol < in > solout
	./test < in > testout
	diff -w solout testout || break
done