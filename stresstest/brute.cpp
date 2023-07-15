#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

long long setBitCount(int N, string S, int X) 
{
    long long ans = 0;

    for(int i = 0; i < N; i++)
    {
        int sum = 0;
        for(int j = i; j < N; j++)
        {
            sum += S[j] - '0';
            if(sum >= X) ans++;
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int N, X;
        string S;
        cin >> N >> S >> X;
        cout << setBitCount(N, S, X) << endl;
    }
}
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1e6 + 5;

// vector<int> solve(int n, vector<int> &A, int q, vector<vector<int>> &queries) 
// {
//     vector<int> ans;
//     for(int i = 0; i < q; i++)
//     {
//         int l = queries[i][0] - 1, r = queries[i][1] - 1;
//         int mx = 0, curr = 0, prev = INT_MIN;
//         for(int j = l; j <= r; j++)
//         {
//             if(A[j] >= prev) curr++;
//             else curr = 1;
//             prev = A[j];
//             mx = max(mx, curr);
//         }
//         ans.push_back(mx);
//     }

//     return ans;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n, q;
//         cin >> n;
//         vector<int> A(n);
//         for(int &x: A)
//             cin >> x;
//         cin >> q;
//         vector<vector<int>> queries;
//         for(int i = 0; i < q; i++)
//         {
//             int l, r;
//             cin >> l >> r;
//             queries.push_back({l, r});
//         }

//         vector<int> ans = solve(n, A, q, queries);
//         for(int x: ans)
//             cout << x << endl;
//     }
// }