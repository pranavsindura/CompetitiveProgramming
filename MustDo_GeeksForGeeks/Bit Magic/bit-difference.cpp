/*
	Count the number of bits that are different in numbers A and B
*/
/*
	Approach 1 -
		The bits that are different for both will show up in A^B
		Then we can simply count the number of bits set in A^B

	Approach 2 - XOR as above but count bits using Brian Kernighan Algorithm
		n&(n-1) unsets the rightmost bit
		So if we perform this while n is nonzero
		Each time we will unset exactly one set bit
		The number of times we perform the loop will be exactly
		The number of bits that are set in the number
*/

// Approach 2
void cp()
{
    int a, b;
    cin >> a >> b;
    int n = a ^ b;
    int cnt = 0;
    while(n)
    {
        n = n & (n - 1);
        cnt++;
    }
    cout << cnt << endl;
}

// Approach 1
void cp()
{
    int a, b;
    cin >> a >> b;
    int n = a ^ b;
    // int cnt = 0;
    // while(n)
    // {
    //     if(n&1)
    //         cnt++;
    //     n >>= 1;
    // }
    // cout<<cnt<<endl;
    cout << __builtin_popcount(a ^ b) << endl;
}