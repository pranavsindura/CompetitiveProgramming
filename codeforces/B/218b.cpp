#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    priority_queue<int> mxpq;
    priority_queue<int, vector<int>, greater<int>> mnpq;
    for(int &x : a)
        cin >> x, mxpq.push(x), mnpq.push(x);

    // Maximum using Max heap
    int temp = n;
    int mx = 0;
    while(temp && !mxpq.empty())
    {
        int x = mxpq.top();
        mxpq.pop();
        mx += x;
        x--;
        if(x)
            mxpq.push(x);
        temp--;
    }

    // Minimum using Min heap
    temp = n;
    int mn = 0;
    while(temp && !mnpq.empty())
    {
        int x = mnpq.top();
        mnpq.pop();
        mn += x;
        x--;
        if(x)
            mnpq.push(x);
        temp--;
    }

    cout << mx << " " << mn;
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