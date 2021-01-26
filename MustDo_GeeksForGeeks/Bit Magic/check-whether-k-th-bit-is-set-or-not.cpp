/*
	Check whether the Kth bit is set in N
*/
/*
	Approach -
		Right shift N by K
		Check if last bit is 1 or 0
*/
void cp()
{
    ll n, k;
    cin >> n >> k;
    cout << ((n >> k) & 1 ? "Yes\n" : "No\n");
}