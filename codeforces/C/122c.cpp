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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
vector<ll> lucky;
void init(ll num)
{
    if(num > 1e10)
        return;
    if(num)
        lucky.pb(num);
    init(num * 10 + 4);
    init(num * 10 + 7);
}

void cp()
{
    ll l, r;
    cin >> l >> r;
    ll left = l;
    ll sum = 0;
    int ind = lower_bound(all(lucky), left) - begin(lucky);
    for(int i = ind; i < sz(lucky); i++)
    {
        if(!sum)
            sum += (min(r, lucky[i]) - left + 1) * lucky[i];
        else
            sum += (min(r, lucky[i]) - left) * lucky[i];
        left = min(r, lucky[i]);
    }
    cout << sum;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    init(0);
    sort(all(lucky));
    while(t--)
    {
        cp();
    }
    return 0;
}