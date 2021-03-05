#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> start, vector<int> duration, vector<int> volume)
{
    int n = start.size();
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = {start[i], start[i] + duration[i], volume[i]};

    sort(arr.begin(), arr.end(), [&](vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    });

    vector<int> dp(n);

    for(int i = 0; i < n; i++)
    {
        dp[i] = arr[i][2];
        int lo = 0, hi = i - 1;
        int pos = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(arr[mid][1] < arr[i][0])
                pos = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        if(~pos) dp[i] += dp[pos];

        if(i) dp[i] = max(dp[i], dp[i - 1]);
    }

    return dp.back();
}

int main()
{
    int n;
    cin >> n;
    vector<int> S(n), D(n), V(n);
    for(auto &x : S)
        cin >> x;
    for(auto &x : D)
        cin >> x;
    for(auto &x : V)
        cin >> x;
    int ans = solve(S, D, V);
    cout << ans << endl;
}

// int solve(vector<string> words)
// {
//     sort(words.begin(), words.end(), [&](string a, string b)
//     {
//         return a.length() < b.length();
//     });

//     int n = words.size();
//     map<string, int> idx;
//     for(int i = 0; i < n; i++)
//         idx[words[i]] = i;

//     vector<int> dp(n);
//     for(int i = 0; i < n; i++)
//     {
//         dp[i] = 1;
//         int m = words[i].length();
//         for(int j = 0; j < m; j++)
//         {
//             string s = words[i].substr(0, j) + words[i].substr(j + 1, n - (j + 1));
//             if(idx.count(s)) dp[i] = max(dp[i], 1 + dp[idx[s]]);
//         }
//     }

//     return *max_element(dp.begin(), dp.end());
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<string> words(n);
//     for(auto &x : words)
//         cin >> x;
//     int ans = solve(words);
//     cout << ans << endl;
// }
