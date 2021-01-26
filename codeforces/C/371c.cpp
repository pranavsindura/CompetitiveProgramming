#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(needa) needa.begin(), needa.end()
#define allr(needa) needa.rbegin(), needa.rend()
#define sz(needa) ((int)needa.size())
#define ln(needa) ((int)needa.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    string s;
    cin >> s;
    ll a, b, c, p, q, r, total, needa = 0, needb = 0, needc = 0;
    cin >> a >> b >> c >> p >> q >> r >> total;
    for(char ss : s)
    {
        if(ss == 'B')
            needa++;
        else if(ss == 'S')
            needb++;
        else
            needc++;
    }
    ll curr = LLONG_MAX;
    if(needa)
        curr = min(curr, a / needa);
    if(needb)
        curr = min(curr, b / needb);
    if(needc)
        curr = min(curr, c / needc);
    ll lo = 0, hi = total + curr + 1;
    ll ans = 0;
    while(lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        //make mid hamburgers
        ll na = max(0LL, mid * needa - a);
        ll nb = max(0LL, mid * needb - b);
        ll nc = max(0LL, mid * needc - c);
        ll cost = na * p + nb * q + nc * r;
        // cout<<na << " "<<nb<< " "<<nc<< " "<<endl;
        if(cost <= total)
        {
            // cout<<"can make "<<mid<<" in "<<cost<<endl;
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans;
    return 0;
}