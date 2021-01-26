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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    vector<int> diff(n + 1, 0);
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        diff[a]++, diff[b + 1]--;
    }

    for(int i = 1; i < n; i++)
        diff[i] = diff[i] + diff[i - 1];

    vector<int> freq;
    for(int i = 0; i < n; i++)
        freq.pb(diff[i]);

    sort(allr(arr));
    sort(allr(freq));

    ll total = 0;
    for(int i = 0; i < n; i++)
        total += arr[i] * 1LL * freq[i];
    cout << total;
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