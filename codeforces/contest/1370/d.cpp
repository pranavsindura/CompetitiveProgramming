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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    auto can = [&](int x, bool odd)
    {
        int cnt = 0;
        //place smaller on odd, any on even
        for(int i = 0; i < n; i++)
        {
            if(odd)
            {
                if(arr[i] <= x)
                    cnt++, odd = !odd;
            }
            else
                cnt++, odd = !odd;
        }

        return (cnt >= k);
    };

    int lo = 1, hi = 1e9;
    int ans = -1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(can(mid, true) || can(mid, false))
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
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