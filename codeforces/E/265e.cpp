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
const ll inf = 1e16;
const int MAXN = 1e5 + 5;

int colour[MAXN], value[MAXN];
vector<pair<ll, int>> top(3);
ll lastval[MAXN];

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> value[i];
    for(int i = 0; i < n; i++)
        cin >> colour[i], colour[i]--;

    while(q--)
    {
        ll a, b;
        cin >> a >> b;
        ll best = 0;
        top[0] = top[1] = top[2] = mp(-inf, -1);
        for(int i = 0; i < n; i++)
            lastval[i] = -inf;

        for(int i = 0; i < n; i++)
        {
            ll same = lastval[colour[i]] + a * value[i];

            ll other = 0;
            if(top[0].ss != colour[i])
                other = max(other, top[0].ff);
            if(top[1].ss != colour[i])
                other = max(other, top[1].ff);

            other += b * value[i];

            ll me = max(same, other);
            best = max(best, me);

            lastval[colour[i]] = max(lastval[colour[i]], me);

            if(top[0].ss == colour[i])
                top[0].ff = max(me, top[0].ff);
            else if(top[1].ss == colour[i])
                top[1].ff = max(me, top[1].ff);
            else
                top[2] = {me, colour[i]};
            sort(allr(top));
        }
        cout << best << endl;
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