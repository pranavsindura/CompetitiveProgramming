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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    reverse(all(arr));
    arr.pop_back();

    queue<pi> q;
    q.push({1, 0});
    int mx_d = 0;
    
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff, d = node.ss;
        mx_d = max(mx_d, d);

        int last = -1;
        vector<int> take;
        while(!arr.empty() && arr.back() > last)
            take.pb(arr.back()), last = arr.back(), arr.pop_back();

        for(int x : take)
            q.push({x, d + 1});
    }

    cout << mx_d << endl;
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