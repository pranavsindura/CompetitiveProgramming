/*
	Longest Consecutive 1s in Binary Representation of N
*/

/*
	Approach 1 - Same as counting consecutive 1s in an array
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
    cout << mx << endl;
}