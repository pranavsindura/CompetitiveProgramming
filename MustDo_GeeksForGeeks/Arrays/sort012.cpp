/*
	Sort array filled with 0,1,2
*/

/*
	Approach 1 - Sorting O(n^2)
	Approach 2 - Sorting O(nlogn)
	Approach 3 - Hashing O(n)
*/

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, c[3] = {0}, x;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            c[x]++;
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < c[i]; j++)
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}