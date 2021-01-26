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

void cp()
{
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    int dist = v1;
    int v = v1;
    int at = 1;
    if(t == 0)
    {
    	cout<<0;
    	return;
    }
    while(at < t)
    {
        int mx = v;
        for(int dv = -d; dv <= d; dv++)
        {
            int v_new = v + dv;
            if(abs(v_new - v2) <= (t - at - 1)*d)
            {
                mx = v_new;
            }
        }
        v = mx;
        dist += v;
        at++;
    }
    cout << dist;
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