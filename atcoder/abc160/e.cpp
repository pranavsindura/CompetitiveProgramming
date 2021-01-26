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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for(int &d : p)
        cin >> d;
    for(int &d : q)
        cin >> d;
    for(int &d : r)
        cin >> d;
    ll total = 0;
    sort(allr(p));
    sort(allr(q));
    sort(allr(r));
    vector<int> v;

    for(int i = 0; i < x; i++)
        v.pb(p[i]);
    for(int i = 0; i < y; i++)
        v.pb(q[i]);
    for(int i = 0; i < c; i++)
        v.pb(r[i]);
    sort(allr(v));
    for(int i = 0; i < x + y; i++)
        total += v[i];
    cout << total;
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