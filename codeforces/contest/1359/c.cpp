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

void cp()
{
    int c, h, t;
    cin >> h >> c >> t;
    if(h - t >= t - c)
    {
        cout << 2 << endl;
    }
    else
    {
        double mindiff = abs(t - h);
        int ans = 1;
        double two_avg = (h + c + 1.0) / 2;
        if(abs(t - two_avg) < mindiff)
            ans = 2;
        int lo = 1, hi = 1e9;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            // 2*mid+1 pours
            int num = 2 * mid + 1;
            double temp;
            temp = ((num + 1.0) / 2.0 * h + (num - 1.0) / 2.0 * c) / (num * 1.0);
            if(abs(t - temp) < mindiff)
            {
                mindiff = abs(t - temp);
                ans = 2 * mid + 1;
            }
            if(temp > t)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        cout << ans << endl;
    }
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