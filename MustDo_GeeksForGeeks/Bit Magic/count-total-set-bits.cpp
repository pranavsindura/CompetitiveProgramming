/*
	Count total number of bits in numbers from 1 to N
*/

/*
	Approach 1 -
		Preprocess number of bits for all N by making prefix
*/
int cnt[1005];
void init()
{
    for(int i = 1; i < 1005; i++)
    {
        int n = i;
        cnt[i] += cnt[i - 1];
        int p = 0;
        while(n)
            n = n & (n - 1), p++;
        cnt[i] += p;
    }
}
void cp()
{
    int n;
    cin >> n;
    cout << cnt[n] << endl;
}