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

ll total;

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void sub(ll n, int i, vector<ll> &arr, ll sel, int s)
{
    if(i == sz(arr))
    {
        int p = (s % 2 ? -1 : 1);
        total += p * (n / sel);
    }
    else
    {
        sub(n, i + 1, arr, sel, s);
        sub(n, i + 1, arr, sel * arr[i] / gcd(sel, arr[i]), s + 1);
    }
}

int main()
{
    FASTIO;
    ll n, m;
    while(cin >> n >> m)
    {
        total = 0;
        vector<ll> arr(m);
        for(int i = 0; i < m; i++)
            cin >> arr[i];
        sub(n, 0, arr, 1, 0);
        cout << total << endl;
    }
    return 0;
}