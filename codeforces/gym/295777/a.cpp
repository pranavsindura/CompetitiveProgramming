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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll a, b;
vector<int> pos;

int cnt(int l, int r)
{
    int lo = 0, hi = sz(pos) - 1;
    // last number with pos <= r
    int last = 0;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if(pos[mid] <= r)
            last = mid + 1, lo = mid + 1;
        else
            hi = mid - 1;
    }
    lo = 0, hi = sz(pos) - 1;
    // last number pos < l
    int first = 0;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if(pos[mid] < l)
            first = mid + 1, lo = mid + 1;
        else
            hi = mid - 1;
    }
    return last - first;
}

ll solve(int l, int r)
{
    if(r - l + 1 == 1)
    {
        int people = cnt(l, r);
        if(people)
            return people * b;
        else
            return a;
    }

    int people = cnt(l, r);
    if(people == 0)
        return a;

    int m = l + (r - l) / 2;
    ll me = people * b * (r - l + 1);
    me = min(me, solve(l, m) + solve(m + 1, r));
    return me;
}

void cp()
{
    int n, k;
    cin >> n >> k >> a >> b;
    for(int i = 0, x; i < k; i++)
        cin >> x, pos.pb(x - 1);
    sort(all(pos));
    cout << solve(0, (1 << n) - 1) << endl;
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