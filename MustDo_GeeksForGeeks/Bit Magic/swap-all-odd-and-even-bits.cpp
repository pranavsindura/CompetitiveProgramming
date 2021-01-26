/*
	Swap Odd and Even Bits of a number
*/

/*
	Approach 1-
		Loop on bits and naively swap odd and even
		Use Bitset or array
*/
void cp()
{
    int n;
    cin >> n;
    bitset<10> num(n);
    for(int i = 1; i < 10; i += 2)
    {
        int temp = num[i];
        num[i] = num[i - 1];
        num[i - 1] = temp;
    }
    cout << num.to_ulong() << endl;
}