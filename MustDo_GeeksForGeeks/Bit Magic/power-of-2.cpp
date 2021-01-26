/*
	Check if Number is Power of 2
*/
/*
		Numbers that are power of 2 have the following representation
		1000000... base 2

	Approach 1 -
		We can check if the number has only 1 bit set, that will make it a power of 2

	Approach 2 -
		For n = 1000000... base 2
		n-1 =   0111111... base 2

		We can check if n&(n-1) == 0
		That will tell us if number is Power of 2
		Beware of n = 0
		Check first that n is non zero
*/
// Approach 2
void cp()
{
    ll n;
    cin >> n;
    if(n && !(n & (n - 1)))
        cout << "YES\n";
    else
        cout << "NO\n";
}
