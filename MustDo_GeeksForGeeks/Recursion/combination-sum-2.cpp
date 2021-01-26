/*
	Subsequence with given sum
*/
/*
	Approach 1 - Brute Force/Recursion
*/
int arr[15];
int target_sum;
int n;
set<vector<int>> ans;
void rec(int pos, vector<int> picked)
{
    if(pos == n)
    {
        int sum = 0;
        for(int x : picked)
            sum += x;
        if(sum == target_sum)
        {
            sort(all(picked));
            ans.insert(picked);
        }
    }
    else
    {
        rec(pos + 1, picked);
        picked.push_back(arr[pos]);
        rec(pos + 1, picked);
    }
}

void cp()
{
    ans.clear();
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> target_sum;
    rec(0, vector<int>());
    if(sz(ans))
    {
        for(vector<int> v : ans)
        {
            cout << "(";
            for(int i = 0; i < sz(v); i++)
            {
                if(i)
                    cout << " " << v[i];
                else
                    cout << v[i];
            }
            cout << ")";
        }
        cout << endl;
    }
    else
    {
        cout << "Empty\n";
    }
}
