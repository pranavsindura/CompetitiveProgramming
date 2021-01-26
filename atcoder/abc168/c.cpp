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
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double minutes = h * 60.0 + m * 1.0;
    // cout << minutes << endl;
    double theta_hour = 2 * PI / (12.0 * 60.0) * minutes;
    double theta_minute = 2 * PI / (60.0) * minutes;
    // cout << theta_hour << " " << theta_minute << endl;
    double x1 = a * 1.0 * cos(theta_hour);
    double y1 = a * 1.0 * sin(theta_hour);
    double x2 = b * 1.0 * cos(theta_minute);
    double y2 = b * 1.0 * sin(theta_minute);
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    cout << setprecision(10) << dist;
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