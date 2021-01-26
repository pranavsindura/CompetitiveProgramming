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
const int MAXN = 1e6 + 5;

int sum(int l, int r, vector<int> &pre)
{
    r = min(r, sz(pre) - 1);
    return (l ? pre[r] - pre[l - 1] : pre[r]);
}

void cp()
{
    int m;
    cin >> m;
    vector<int> q(m);
    for(int &x : q)
        cin >> x;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    sort(all(q));
    sort(allr(arr));

    int pos = 0;
    int cost = 0;
    while(pos < n)
    {
        for(int i = 0; i < q[0] && pos < n; i++)
        {
            cost += arr[pos];
            pos++;
        }
        pos += 2;
    }
    cout << cost;
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