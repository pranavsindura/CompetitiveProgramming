#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
int hash_sum[MAXN];
void cp()
{
    clr(hash_sum, 0);
    int k;
    string s;
    cin >> k >> s;
    int n = ln(s);
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = s[i] - '0';
    int sum = 0;
    ll count_subarray = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == k)
        {
            count_subarray++;
        }
        if(sum - k >= 0 && hash_sum[sum - k])
        {
            count_subarray += hash_sum[sum - k];
        }
        hash_sum[sum]++;
    }
    cout << count_subarray;
}

// void cp()
// {
//     int k;
//     string s;
//     cin >> k >> s;

//     int n = ln(s);
//     int pref[n], suff[n + 1];

//     int cnt = 0;
//     ll ans = 0, cons_zero = 0;
//     vector<int> one;

//     for(int i = 0; i < n; i++)
//         if(s[i] == '1')
//             one.pb(i);

//     for(int i = 0; i < n; i++)
//     {
//         pref[i] = cnt;
//         if(s[i] == '0')
//             cnt++;
//         else
//             cons_zero += cnt * 1LL * (cnt + 1) / 2, cnt = 0;
//     }
//     if(s.back() == '0')
//         cons_zero += cnt * 1LL * (cnt + 1) / 2;

//     if(k == 0)
//     {
//         cout << cons_zero;
//         return;
//     }

//     cnt = 0;
//     for(int i = n - 1; i >= 0; i--)
//     {
//         suff[i] = cnt;
//         if(s[i] == '0')
//             cnt++;
//         else
//             cnt = 0;
//     }

//     for(int i = k - 1; i < sz(one); i++)
//     {
//         ans += (pref[one[i - k + 1]] + 1) * 1LL * (suff[one[i]] + 1);
//     }
//     cout << ans;
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