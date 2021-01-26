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


ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b, ll c, ll d)
{
    ll ans = a * b / gcd(a, b);
    ans = ans * c / gcd(ans, c);
    ans = ans * d / gcd(ans, d);
    return ans;
}

int main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    while(n && m)
    {
        vector<ll> arr(n);
        for(ll &x : arr)
            cin >> x;
        vector<ll> ht(m);
        for(ll &x : ht)
            cin >> x;

        for(ll h : ht)
        {
            ll la = INT_MIN;
            ll lb = INT_MAX;
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    for(int k = j + 1; k < n; k++)
                    {
                        for(int l = k + 1; l < n; l++)
                        {
                            ll x = lcm(arr[i], arr[j], arr[k], arr[l]);
                            ll a = h/x;
                            a *= x;
                            la = max(la, a);
                            ll b = (h+x-1)/x;
                            b *= x;
                            lb = min(lb, b);
                        }
                    }
                }
            }
            cout<<la<<" "<<lb<<endl;
        }
        cin >> n >> m;
    }
    return 0;
}