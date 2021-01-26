/*
	Set the Kth bit to 1 in number N
*/
/*
	Approach - OR the number with 2^k
*/

void cp()
{
    int n, k;
    cin >> n >> k;
    n |= (1 << k);
    cout << n << endl;
}