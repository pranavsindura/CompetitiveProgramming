/*
	Find First set bit
*/
/*
	Approach -
		Right shift until you find 1,
		Careful of n = 0 case
*/
void cp()
{
    int n;
    cin >> n;
    if(n == 0)
    {
        cout << 0 << endl;
        return;
    }
    int p = 0;
    while((n & 1) == 0)
    {
        n >>= 1;
        p++;
    }
    cout << p + 1 << endl;
}