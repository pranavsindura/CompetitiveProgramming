/*
	Check if Number is Sparse or Not
	Number of consecutive 1s must be < 2
*/

/*
	Approach 1 -
		Count maximum consecutive 1s. Must be < 2
*/
void cp()
{
    int n;
    cin >> n;
    int cnt = 0;
    int mx = 0;
    while(n)
    {
        if(n & 1)
            cnt++;
        else
            cnt = 0;
        n >>= 1;
        mx = max(mx, cnt);
    }
    cout << (mx < 2) << endl;
}
