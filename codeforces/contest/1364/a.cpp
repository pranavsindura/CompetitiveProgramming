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
    int n, d, sum = 0;
    cin >> n >> d;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x, sum += x;
    int i = 0, j = n - 1;
    int mx = 0;
    bool ok = false;
    int here = sum;
    for(int i = 0; i < n; i++)
    {
        if(here % d != 0)
        {
            ok = true;
            mx = max(mx, n - i);
            break;
        }
        here -= arr[i];
    }
    here = sum;
    for(int i = n - 1; i >= 0; i--)
    {
        if(here % d != 0)
        {
            ok = true;
            mx = max(mx, i + 1);
            break;
        }
        here -= arr[i];
    }
    if(ok)
        cout << mx << endl;
    else
        cout << -1 << endl;
}

int main()
{
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