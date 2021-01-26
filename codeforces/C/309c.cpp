#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<int> mem(n), fit(m);
    for(int &x : mem)
        cin >> x;
    for(int &x : fit)
        cin >> x;
    sort(allr(mem));
    sort(all(fit));

    vector<int> copy(n);

    auto check = [&](int p)
    {
        vector<int> cnt(32, 0);
        copy = mem;
        for(int i = 0; i <= p; i++)
            cnt[fit[i]]++;
        for(int b = 30; b >= 0; b--)
        {
            int req = cnt[b];
            for(int i = 0; i < n && req; i++)
            {
                int can = copy[i] / (1 << b);
                int take = min(can, req);
                req -= take;
                copy[i] -= take * (1 << b);
            }
            if(req)
                return false;
        }
        return true;
    };

    int lo = 0, hi = m - 1;
    int ans = -1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(check(mid))
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << ans + 1;
}

// void cp()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> mem(n);
//     vector<vector<int>> cnt(40);

//     for(int i = 0; i < n; i++)
//         cin >> mem[i];

//     for(int i = 0; i < m; i++)
//     {
//         int x;
//         cin >> x;
//         cnt[x].pb(1);
//     }

//     int total = 0;
//     for(int b = 0; b < 32; b++)
//     {
//         sort(all(cnt[b]));
//         while(!cnt[b].empty())
//         {
//             for(int i = 0; i < n && !cnt[b].empty(); i++)
//                 if((mem[i] >> b) & 1)
//                     total += cnt[b].back(), cnt[b].pop_back(), mem[i] = mem[i] & ~(1 << b);

//             while(sz(cnt[b]) > 1)
//             {
//                 cnt[b + 1].pb(cnt[b].back());
//                 cnt[b].pop_back();
//                 cnt[b + 1].back() += cnt[b].back();
//                 cnt[b].pop_back();
//             }

//             if(sz(cnt[b]) & 1)
//                 cnt[b + 1].pb(cnt[b].back()), cnt[b].pop_back();
//         }
//     }

//     cout << total;
// }

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}