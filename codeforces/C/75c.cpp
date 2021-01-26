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

void cp()
{
    int a, b;
    cin >> a >> b;
    int g = __gcd(a, b);

    vector<int> div;
    for(int i = 1; i <= sqrt(g); i++)
    {
        if(g % i == 0)
        {
            if(g / i == i)
                div.pb(i);
            else
                div.pb(i), div.pb(g / i);
        }
    }
    sort(all(div));
    
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int lo = 0, hi = sz(div) - 1;
        int ans = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(div[mid] < l)
                lo = mid + 1;
            else if(div[mid] > r)
                hi = mid - 1;
            else
            {
                ans = max(ans, div[mid]);
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }
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