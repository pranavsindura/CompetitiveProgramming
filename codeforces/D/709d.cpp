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
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

inline bool check(ll x)
{
    return (ll)sqrt(x) * (ll)sqrt(x) == x;
}

void no()
{
    cout << "Impossible\n";
    exit(0);
}

void cp()
{
    int a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;

    ll temp = 8LL * a00 + 1;
    if(!check(temp))
        no();

    int zeros = (1 + (int)sqrt(temp)) / 2;

    temp = 8LL * a11 + 1;
    if(!check(temp))
        no();

    int ones = (1 + (int)sqrt(temp)) / 2;

    if(!a00 && !a01 && !a10 && !a11)
    {
        cout << "0" << endl;
        return;
    }
    else if(a00 && !a01 && !a10 && !a11)
    {
        cout << string(zeros, '0') << endl;
        return;
    }
    else if(!a00 && !a01 && !a10 && a11)
    {
        cout << string(ones, '1') << endl;
        return;
    }

    string pref, mid, suff;
    mid = string(zeros, '0');

    // muls of zeros from a10, need these many ones in front
    int need = a10 / zeros;
    if(need > ones)
        no();
    a10 -= need * zeros;
    pref = string(need, '1');
    ones -= need;

    // muls of zeros from a01, need these many ones at end
    need = a01 / zeros;
    if(need > ones)
        no();
    a01 -= need * zeros;
    suff = string(need, '1');
    ones -= need;

    if(ones > 1)
        no();

    if(ones == 1)
    {
        if(a10 + a01 != zeros)
            no();
        mid = string(a01, '0') + "1" + string(a10, '0');
    }

    string ans = pref + mid + suff;
    cout << ans << endl;
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