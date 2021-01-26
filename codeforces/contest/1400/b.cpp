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
    ll N, M, A, B, s, w;
    cin >> N >> M >> A >> B >> s >> w;
    if(s > w)
        swap(A, B), swap(s, w);
    if(N < M)
        swap(N, M);
    ll res = LLONG_MIN;
    for(int i = 0; i <= A; i++)
    {
        // take i units of A

        ll ans = 0;
        ll n = N, m = M, a = i, b = B;
        ll mula = n / s;
        ll takea = min(mula, a);
        ans += takea;
        a -= takea;
        n -= takea * s;

        a += (A - i);
        mula = m / s;
        takea = min(mula, a);

        ans += takea;
        a -= takea;
        m -= takea * s;
        // take all B
        ll mulb = n / w;
        ll takeb = min(mulb, b);
        ans += takeb;
        b -= takeb;
        n -= takeb * w;
        // let follower take all B
        mulb = m / w;
        takeb = min(mulb, b);

        ans += takeb;
        b -= takeb;
        m -= takeb * w;
        res = max(res, ans);
    }

    for(int i = 0; i <= B; i++)
    {
        // take i units of A

        ll ans = 0;
        ll n = N, m = M, a = A, b = i;
        // take all B
        ll mulb = n / w;
        ll takeb = min(mulb, b);

        ans += takeb;
        b -= takeb;
        n -= takeb * w;
        // let follower take all B
        b += (B - i);
        mulb = m / w;
        takeb = min(mulb, b);

        ans += takeb;
        b -= takeb;
        m -= takeb * w;
        ll mula = n / s;
        ll takea = min(mula, a);
        ans += takea;
        a -= takea;
        n -= takea * s;

        mula = m / s;
        takea = min(mula, a);

        ans += takea;
        a -= takea;
        m -= takea * s;

        res = max(res, ans);
    }

    cout << res << endl;
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