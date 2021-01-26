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
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

int conv(vector<int> s)
{
    int ans = 0;
    reverse(all(s));
    for(int x : s)
    {
        ans *= 10;
        ans += x;
    }
    return ans;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a, b;
        while(n)
        {
            a.pb(n % 10);
            n /= 10;
        }
        while(m)
        {
            b.pb(m % 10);
            m /= 10;
        }
        int mx = conv(a)+conv(b);
        for(int i = 0; i < sz(a); i++)
        {
            for(int j = 0; j < sz(b); j++)
            {
                swap(a[i], b[j]);
                mx = max(mx, conv(a) + conv(b));
                swap(a[i], b[j]);
            }
        }
        cout << mx << endl;
    }
    return 0;
}