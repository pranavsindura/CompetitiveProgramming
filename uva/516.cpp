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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 100005;

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}

void cp()
{
    while(true)
    {
        vector<pii> fac;
        int a, b;
        cin >> a;
        if(a == 0)
            break;
        cin >> b;
        fac.pb({a, b});
        string s;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> a >> b)
        {
            fac.pb({a, b});
        }
        ll num = 1;
        for(pii x : fac)
            num *= fpow(x.ff, x.ss);
        num--;
        map<int, int, greater<int>> new_fac;
        while(num % 2 == 0)
            num /= 2, new_fac[2]++;
        for(int i = 3; i <= sqrt(num); i += 2)
        {
            while(num % i == 0)
                num /= i, new_fac[i]++;
        }
        if(num > 1)
            new_fac[num]++;
        vector<int> v;
        for(auto x : new_fac)
            v.pb(x.ff), v.pb(x.ss);
        for(int i = 0; i < sz(v); i++)
        {
            if(i)
                cout << " " << v[i];
            else
                cout << v[i];
        }
        cout << endl;
    }
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