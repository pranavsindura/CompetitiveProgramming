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
    vector<pi> arr(3);
    for(auto &x : arr)
        cin >> x.ff >> x.ss;
    sort(all(arr));
    int ans = 3;
    if((arr[0].ff == arr[1].ff && arr[1].ff == arr[2].ff) || (arr[0].ss == arr[1].ss && arr[1].ss == arr[2].ss))
        ans = 1;
    else
    {
        bool ok = false;
        do
        {
            if(arr[0].ff == arr[1].ff)
            {
                if(arr[2].ss >= max(arr[0].ss, arr[1].ss) || arr[2].ss <= min(arr[0].ss, arr[1].ss))
                    ok = true;
            }
            if(arr[0].ss == arr[1].ss)
            {
                if(arr[2].ff >= max(arr[0].ff, arr[1].ff) || arr[2].ff <= min(arr[0].ff, arr[1].ff))
                    ok = true;
            }
        }
        while(next_permutation(all(arr)));
        if(ok)
            ans = 2;
    }
    cout << ans;
}

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