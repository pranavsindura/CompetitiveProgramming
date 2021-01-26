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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 998244353;
const int MAXN = 1e6 + 5;

/*
	look at b[i]
	find its position in a -> j
	we can remove neighbours of a[j]
	but if some neighbour occurs later in b, we cannot remove it
	based on this find choices of removal for each b[i]
*/

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), idx(n + 1);
    for(int i = 0; i < n; i++)
        cin >> a[i], idx[a[i]] = i;
    for(int &x : b)
        cin >> x;

    set<int> req;

    ll ans = 1;
    for(int i = m - 1; i >= 0; i--)
    {
        int me = 0;
        int pos = idx[b[i]];
        if(pos + 1 < n)
            if(!req.count(a[pos + 1]))
                me++;
        if(pos - 1 >= 0)
            if(!req.count(a[pos - 1]))
                me++;
        ans *= me;
        ans %= mod;
        req.insert(b[i]);
    }

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}