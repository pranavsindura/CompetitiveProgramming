#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 34943
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

char hex(int a)
{
    if(a <= 9 && a >= 0)
        return '0' + a;
    else
        return 'A' + (a - 10);
}

int main()
{
    FASTIO;
    string s;
    getline(cin, s);
    while(true)
    {
        if(s == "#")
            break;
        int val = 0;
        int n = ln(s);
        for(int i = 0; i < n; i++)
        {
            val = (int(s[i]) + (val << 8)) % mod;
        }
        val = (val * 1LL << 16LL) % mod;
        int diff = (mod - val) % mod;
        vector<int> h;
        while(diff)
        {
            h.pb(diff % 16);
            diff /= 16;
        }
        int d = sz(h);
        for(int i = 0; i < 4 - d; i++)
        {
            h.pb(0);
        }
        cout << hex(h[3]) << hex(h[2]) << " " << hex(h[1]) << hex(h[0]) << endl;
        getline(cin, s);
    }
    return 0;
}
