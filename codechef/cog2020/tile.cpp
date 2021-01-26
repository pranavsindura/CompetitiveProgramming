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
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        int po = 0;
        ll temp = n / 2;
        ll rem = n % 2;
        ll ans;
        if(rem)
            ans = ((temp % mod * 6 % mod) % mod * (rem * 4) % mod) % mod;
        else
            ans = (temp % mod * 6 % mod) % mod;
        cout << ans << endl;
    }
    return 0;
}