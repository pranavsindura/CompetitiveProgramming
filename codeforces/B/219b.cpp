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
#define nl cout<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    ll p, q, temp, ans;
    int mx = 0;
    cin >> p >> q;
    temp = p;
    ans = p;
    while(temp)
    {
        if(temp % 10 == 9)
            mx++;
        else
            break;
        temp /= 10;
    }
    ll m = 10;
    for(int i = 0; i < 18; i++)
    {
        ll cur = p - p % m - 1;
        m = m * 10;
        if(cur < 0)
            continue;
        if(p-cur > q)
        	break;
        temp = cur;
        int cnt=0;
        while(temp)
        {
            if(temp % 10 == 9)
                cnt++;
            else
                break;
            temp /= 10;
        }
        if(cnt > mx)
        	mx = cnt, ans = cur;
    }
    cout<<ans;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}