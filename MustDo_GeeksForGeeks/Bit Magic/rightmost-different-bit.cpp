/*
	Find the first bit that differs in 2 numbers
*/
/*
	Approach -
	We have to find the rightmost different bit
	We will XOR the two numbers, any 2 bits that are different will turn 1 in n^m
	After that we can find the first set bit
*/
void cp()
{
    int n, m;
    cin >> n >> m;
    int res = n ^ m;
    bool found = false;
    int pos = 0;
    while(res && (res & 1) == 0)
        pos++, res >>= 1;
    if(res)
        cout << pos + 1 << endl;
    else
        cout << -1 << endl;
}