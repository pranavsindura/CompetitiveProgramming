/*
	Alone in a Couple
	Every number repeats twice except one with repeats once find it
*/

/*
	Approach 1 - XOR all numbers
*/
void cp()
{
    int n, ans = 0, x;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x, ans ^= x;
    cout << ans << endl;
}