#include<bits/stdc++.h>
#define ll long long int
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n, k;
    cin >> n >> k;
    int blank = n / 2;
    if(n == 1 && k == 0)
    {
        cout << 1;
        return;
    }
    if((k < blank) || (!blank && k))
    {
        cout << -1;
        return;
    }

    vector<int> arr;
    arr.pb((k - blank + 1));
    arr.pb((k - blank + 1) * 2);
    while(sz(arr) < n)
    {
        arr.pb(arr.back() + 1);
    }
    for(int x : arr)
        cout << x << " ";
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