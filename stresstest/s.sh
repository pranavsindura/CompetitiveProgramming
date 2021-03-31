for (( i = 0; ; i++ )); do
	echo $i
	# python gen.py > in
	./gen > in
	./sol < in > out1
	./brute < in > out2
	diff -w out1 out2 || break
done