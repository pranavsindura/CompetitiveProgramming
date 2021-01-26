#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n), B(m), a, b;
    map<int, int> alice, bob;
    for(int &x : A)
        cin >> x, alice[x]++;
    for(int &x : B)
        cin >> x, bob[x]++;

    for(int x : A)
    {
        if(alice[x] > bob[x])
            a.push_back(x), alice[x]--;
    }
    for(int x : B)
    {
        if(bob[x] > alice[x])
            b.push_back(x), bob[x]--;
    }

    sort(all(a)), sort(all(b));
    bool ok = false;
    if(sz(a) > sz(b)) ok = true;
    else
    {
        while(!a.empty() && !b.empty())
        {
            int x = a.back();
            a.pop_back();
            int y = b.back();
            b.pop_back();
            if(x > y)
                ok = true;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
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

