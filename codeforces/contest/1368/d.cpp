#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> bit_cnt(21, 0);
    for(int i = 0; i < n; i++)
    {
        for(int b = 0; b < 21; b++)
        {
            if((arr[i] >> b) & 1)
                bit_cnt[b]++;
        }
    }
    vector<ll> res(n, 0);
    for(int i = 0; i < sz(bit_cnt); i++)
    {
        for(int j = 0; j < bit_cnt[i]; j++)
        {
            res[j] = res[j] | (1 << i);
        }
    }
    ll sum = 0;
    for(ll x : res)
        sum += x * x;
    cout << sum;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}