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
const int MAXN = 1e5 + 5;
ll pref[MAXN];
pair<ll, ll> op[MAXN];
int m;
ll find(ll i)
{
    int lo = 0, hi = m - 1;
    int pos = m - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(i <= pref[mid])
            pos = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }

    if(op[pos].ff == 1)
        return op[pos].ss;
    i = i - pref[pos - 1] - 1;
    i = i % op[pos].ss;
    return find(i);
}

void cp()
{
    cin >> m;
    pref[0] = -1;
    for(int i = 0; i < m; i++)
    {
        if(i)
            pref[i] = pref[i - 1];
        int t;
        cin >> t;
        if(t == 1)
        {
            int x;
            cin >> x;
            op[i] = {1, x};
            pref[i]++;
        }
        else
        {
            int len, rep;
            cin >> len >> rep;
            pref[i] += len * 1LL * rep;
            op[i] = {2, len};
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        ll pos;
        cin >> pos;
        pos--;
        ll num = find(pos);
        cout << num << " ";
    }
    cout << endl;
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