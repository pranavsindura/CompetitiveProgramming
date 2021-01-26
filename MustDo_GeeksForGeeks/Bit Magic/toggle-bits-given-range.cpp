/*
	Give N, L, R
	Toggle all bits of N in range [L, R]
*/

/*
	Approach 1 -
		Loop from L to R and XOR the number with 2^i

	Approach 2 - Using prefix logic
		Toggle all bits from [0, R]
		Toggle all bits from [0, L-1]

		To toggle all bits in range [0, N-1]
		We need to xor the number with 11111... n-1 times
		We can get that as 2^N - 1

		a = a^((1<<N)-1)
*/

// Approach 2
void cp()
{
    // int n, l, r;
    // cin >> n >> l >> r;
    // l--, r--;
    // int num = (1 << (r + 1));
    // num--;
    // n = n ^ num;
    // if(l)
    // {
    //     num = (1 << l);
    //     num--;
    //     n = n ^ num;
    // }
    // cout << n << endl;
    int n, l, r;
    cin >> n >> l >> r;
    n = n ^ ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);
    cout << n << endl;
}