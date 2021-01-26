/*
    LARGEST NUMBER FORMED FROM ARRAY
    After a series of concatenations
*/

/*
    Approach 1 - Check all Permutations O(n!)
    Approach 2 - Sort lexicographically O(nlogn) with slight modification
    If two string have different lengths, to compare them use a+b < b+a
    because one would be placed after other.
*/

void cp()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;
    sort(allr(arr), [](string a, string b)
    {
        return a + b < b + a;
    });
    for(string x : arr)
        cout << x;
    cout << endl;
}