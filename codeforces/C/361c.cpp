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
const int MAXN = 5e3 + 5;

int make[MAXN], arr[MAXN];
vector<vector<int>> query;
bool check(int t, int l, int r, int d)
{
    if(t == 1)
    {
        for(int i = l; i <= r; i++)
            arr[i] += d;
        return 1;
    }
    else
    {
        int mx = INT_MIN;
        for(int i = l; i <= r; i++)
            mx = max(mx, arr[i]);
        return mx == d;
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;

    query.resize(q);
    for(auto &v : query)
        v.resize(4), cin >> v[0] >> v[1] >> v[2] >> v[3], v[1]--, v[2]--;

    bool ok = true;
    for(int i = 0; i < n; i++)
    {
        int res = 1e9;
        int add = 0;
        for(int j = 0; j < q; j++)
        {
            if(query[j][1] > i || query[j][2] < i)
                continue;
            if(query[j][0] == 1)
                add += query[j][3];
            else
            	res = min(res, query[j][3] - add);
        }
        if(res >= -1e9 && res <= 1e9)
            make[i] = res;
        else
            ok = false;
    }

    for(int i = 0; i < n; i++)
        arr[i] = make[i];

    for(auto v : query)
        ok &= check(v[0], v[1], v[2], v[3]);

    if(ok)
    {
        cout << "YES\n";
        for(int i = 0; i < n; i++)
            cout << make[i] << " ";
        cout << endl;
    }
    else
        cout << "NO\n";
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