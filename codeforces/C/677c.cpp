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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

int get_val(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else if(c >= 'a' && c <= 'z')
        return c - 'a' + 36;
    else if(c == '-')
        return 62;
    else
        return 63;
}

int count_zero(int num)
{
    //count upto 6 bits
    int zero = 0;
    for(int i = 0; i < 6; i++)
    {
        if(!(num & 1))
            zero++;
        num = num >> 1;
    }
    return zero;
}

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y = y >> 1;
    }
    return res % mod;
}

void cp()
{
    string s;
    cin >> s;
    int zero = 0;
    for(char x : s)
        zero += count_zero(get_val(x));
    cout << fpow(3LL, zero);
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