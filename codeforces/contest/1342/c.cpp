#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);
ll a, b, q;
ll lcm, len;
int pref[200 * 200 + 5];
ll solve(ll a)
{
    if(a <= lcm)
    {
        return pref[a];
    }
    else
    {
        ll ans = 0;
        ll n = a / lcm;
        // ans *= len;
        // ans -= len - a % len;
        ans =  pref[lcm] * n + pref[a % lcm];
        return ans;
    }
}
void cp()
{
    cin >> a >> b >> q;
    lcm = a * b / __gcd(a, b);
    pref[0] = 0;
    for(int i = 1; i <= lcm; i++)
    {
        pref[i] = pref[i - 1];
        if((i % a) % b == (i % b) % a)
            pref[i]++;
    }
    len = max(a, b);
    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << r - l + 1 - solve(r) + solve(l - 1) << " ";
    }
    nl;
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