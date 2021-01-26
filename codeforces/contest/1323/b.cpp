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

int counta[1000005], countb[1000005];

int main()
{
    FASTIO;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
            continue;
        int j;
        for(j = i; j < n && a[j] ; j++);
        int len = j - i;
        for(int x = 1; x <= len; i = x++)
        {
            counta[x] += len - x + 1;
        }
        i = j;
    }
    for(int i = 0; i < m; i++)
    {
        if(b[i] == 0)
            continue;
        int j;
        for(j = i; j < m && b[j] ; j++);
        int len = j - i;
        for(int x = 1; x <= len; i = x++)
        {
            countb[x] += len - x + 1;
        }
        i = j;
    }

    ll ans = 0;
    for(int i = 1; i < 1000005; i++)
    {
        if(k % i == 0 && k / i <= m)
            ans += counta[i] * countb[k / i] * 1LL;
    }
    cout << ans;
    return 0;
}