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
    double n;
    cin >> n;
    n = n * 2.0;

    double interior = 180.0 - 360.0 / n;
    double alpha = interior / 2.0;
    double theta = 360.0 / n;
    double x = sin(alpha * PI / 180.0) / sin(theta * PI / 180.0);
    double side = x * cos(theta / 2.0 * PI / 180.0);
    cout << fixed << setprecision(10) << side * 2.0 << endl;
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