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

double fpow(double x, int y)
{
    double res = 1;
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
    int n, player;
    double p;
    cin >> n >> p >> player;
    if(p <= eps)
    {
        cout << "0.0000" << endl;
        return;
    }
    double q = 1.0 - p;
    double res = fpow(q, player - 1) * p * (1.0 / (1.0 - fpow(q, n)));
    cout << setprecision(4) << fixed << res << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}