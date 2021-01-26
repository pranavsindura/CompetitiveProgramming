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
const int MAXN = 4e5 + 5;
vector<ll> dig, pref;
void gen()
{
    dig.pb(1);
    for(int i = 2; i < MAXN; i++)
    {
        int d = log10(i) + 1;
        dig.pb(dig.back() + d);
    }
    pref.pb(0);
    for(int i = 0; i < MAXN; i++)
        pref.pb(pref.back() + dig[i]);
}

void cp()
{
    ll n;
    cin >> n;
    int pos = 1;
    int lo = 1, hi = sz(pref) - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(pref[mid] < n)
            lo = mid + 1;
        else
            pos = mid, hi = mid - 1;
    }
    // 1 based offset
    int off = dig[pos - 1] - pref[pos] + n;
    // dbg(off);
    // lies in 12345678910....rep(pos)
    // at off-th position
    // find the digit that the off pos ends with
    int pos2 = 1;
    lo = 1, hi = dig[pos];
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(dig[mid - 1] < off)
            lo = mid + 1;
        else
            pos2 = mid, hi = mid - 1;
    }
    int sz = log10(pos2) + 1;
    int pos3 = off - (pos2 > 1 ? dig[pos2 - 2] : 0);
    vector<int> rep;
    while(pos2)
        rep.pb(pos2 % 10), pos2 /= 10;
    reverse(all(rep));
    cout << rep[pos3 - 1] << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    gen();
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}