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
    int n, k;
    cin >> n >> k;
    int small_div = 1;
    bool found = false;
    int temp = n;
    vector<int> factor;
    while(temp % 2 == 0)
    {
        factor.pb(2);
        temp /= 2;
    }
    for(int i = 3; i <= sqrt(temp); i += 2)
    {
        while(temp % i == 0)
        {
            factor.pb(i);
            temp /= i;
        }
    }
    if(temp > 1)
    {
        factor.pb(temp);
    }

    small_div = factor[0];
    ll res = n + small_div;
    //now res is divisible by 2
    res += 2LL*(k - 1);
    cout << res << endl;
}

int main()
{
    void init();
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