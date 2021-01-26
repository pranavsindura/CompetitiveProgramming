#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

double dist(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool calc(pair<double, double> a, pair<double, double> b, double r)
{
    if(dist(a, b)-r <= eps)
        return true;6
    else
        return false;
}

set<pair<int, int>> warm;
// bool warmb[1005][1005];
struct v{
    double x,y,r;
};
#define v struct v
int main()
{
    FASTIO;
    // memeset(warmb, false, sizeof(warmb));
    int xa, ya, xb, yb, t;
    cin >> xa >> ya >> xb >> yb >> t;
    // cout << xa << " " << ya << " " << xb << " " << yb << endl;
    int c = 0;
    vector<v> arr;
    while(t--)
    {
        v e;
        // double  x, y, r;
        cin >> e.x >> e.y >> e.r;
        arr.push_back(e);
    }
    for(v e: arr)
    {
        // cout<<c<<": "<<endl;
        c++;
        for(int i = min(xa,xb); i <= max(xa,xb); i++)
        {
            if(calc(mp(i * 1.0, ya * 1.0), mp(e.x, e.y), e.r))
            {
                // cout << "warm: " << i << " " << ya << endl;
                warm.insert(mp(i, ya));
            }
            if(calc(mp(i * 1.0, yb * 1.0), mp(e.x, e.y), e.r))
            {
                // cout << "warm: " << i << " " << yb << endl;

                warm.insert(mp(i, yb));
            }
        }
        for(int i = min(ya, yb); i <= max(ya, yb); i++)
        {
            if(calc(mp(xa * 1.0, i * 1.0), mp(e.x, e.y), e.r))
            {
                // cout << "warm: " << xa << " " << i << endl;

                warm.insert(mp(xa, i));
            }
            if(calc(mp(xb * 1.0, i * 1.0), mp(e.x, e.y), e.r))
            {
                // cout << "warm: " << xb << " " << i << endl;

                warm.insert(mp(xb, i));
            }
        }
    }
    // for(auto item : warm)
    //     cout << item.first << " " << item.second << endl;
    // cout << endl;
    int s = sz(warm);
    int total = (abs(xa - xb)-1)*2 + (abs(ya - yb)-1)*2 + 4;
    cout << total - s;
    return 0;
}