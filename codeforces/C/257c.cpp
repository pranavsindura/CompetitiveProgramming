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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ld to_deg(ld ang)
{
	return ang*180.0/PI;
}
void cp()
{
    int n;
    cin >> n;
    vector<pair<ld, ld>> man;
    for(int i = 0; i < n; i++)
    {
        ld x, y;
        cin >> x >> y;
        man.pb({x, y});
    }
    vector<ld> angles;
    for(int i = 0; i < n; i++)
    {
        ld ang = atan2(man[i].ss, man[i].ff);
        ang = to_deg(ang);
        angles.pb(ang);
    }
    sort(all(angles));
    ld diff = 360.0 - (angles[0] - angles.back() + 360.0);
    for(int i=1;i<n;i++)
    {
    	diff = min(diff, 360.0 - (angles[i] - angles[i-1]));
    }
    cout << setprecision(10) << fixed << diff + eps;
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