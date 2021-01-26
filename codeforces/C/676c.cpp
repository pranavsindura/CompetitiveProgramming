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
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> prefa, prefb;
    
    prefa.pb(s[0] == 'a');
    prefb.pb(s[0] == 'b');

    for(int i = 1; i < n; i++)
        prefa.pb(prefa.back() + (s[i] == 'a')), prefb.pb(prefb.back() + (s[i] == 'b'));

    int ans = 0;
    int lo = 1, hi = n;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        bool can = false;
        for(int i = mid - 1; i < n; i++)
        {
            int l = i - mid + 1, r = i;

            int a = prefa[r] - (l ? prefa[l - 1] : 0);
            int b = prefb[r] - (l ? prefb[l - 1] : 0);

            if(min(a, b) <= k)
                can = true;
        }
        if(can)
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
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