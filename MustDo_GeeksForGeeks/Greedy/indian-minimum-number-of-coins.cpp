/*
	Given Indian Currency coins/notes
	Find minimum coins/notes you need to make change of Rs. N
	{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}
*/

/*
	This is generally a DP Problem, but
	Observation is that Any Higher denomination can be written as a linear combination of the smaller denomination
	This allows to be greedily pick The highest denomination and continue with the smaller one
*/
vector<int> den = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
void cp()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = sz(den) - 1; i >= 0; i--)
    {
        int mul = n / den[i];
        ans += mul;
        n = n % den[i];
        for(int j = 0; j < mul; j++)
            cout << den[i] << " ";
    }
    cout << endl;
    //Greedy works because every higher denomination can be written as a combination of the smaller ones
    //So you can simply pick the highest one
}
