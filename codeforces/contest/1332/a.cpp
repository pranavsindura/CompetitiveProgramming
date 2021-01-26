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
    int a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    bool ok = false;
    int dx = b - a;
    int dy = d - c;
    if(x + dx >= x1 && x + dx <= x2 && y + dy >= y1 && y + dy <= y2)
    {
        if(a + b != 0 && abs(x2 - x1) == 0)
        {
            //still false
            ok = false;
        }
        else if(c + d != 0 && abs(y2 - y1) == 0)
        {
            ok = false;
        }
        else
        {
            ok = true;
        }
    }
    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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