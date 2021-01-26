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
    int n, c = 0;
    cin >> n;
    ll ans = 0;
    ll p = 1;
    while(n)
    {
        c++;
        int r = n % 10;
        if(r == 7)
            ans += p;
        n /= 10;
        p *= 2;
    }
    p = 1;
    for(int i = 1; i <= c; i++)
    {
        ans += p;
        p *= 2;
    }
    cout << ans;
    return 0;
}
