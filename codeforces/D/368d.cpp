#include<bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

/*
	So multisets are slow :/

	Group the indices by index%p
	this way we can group together the numbers which can form a series
	pick m consecutive of them and see if they can form the array b
	Handle which elements are required according to their frequency with maps
*/

void cp()
{
    int n, m, p;
    cin >> n >> m >> p;
    map<int, int> need;
    vector<int> a(n), b(m);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x, need[x]++;

    vector<vector<int>> group(p);
    for(int i = 0; i < n; i++)
        group[i % p].pb(i);

    vector<int> ans;
    for(int i = 0; i < p; i++)
    {
        if(sz(group[i]) < m) continue;

        map<int, int> freq;
        map<int, int> req;
        for(int j = 0; j < m; j++)
            req[b[j]]++;

        for(int j = 0; j < m; j++)
            if(req.count(a[group[i][j]]) && --req[a[group[i][j]]] == 0)
                req.erase(a[group[i][j]]);

        for(int j = 0; j < m; j++)
            freq[a[group[i][j]]]++;

        if(req.empty())
            ans.pb(group[i][0]);

        for(int j = m; j < sz(group[i]); j++)
        {
            int rem = a[group[i][j - m]];
            int add = a[group[i][j]];

            freq[rem]--;
            if(freq[rem] < need[rem])
                req[rem]++;

            freq[add]++;
            if(req.count(add) && --req[add] == 0)
                req.erase(add);

            if(req.empty())
                ans.pb(group[i][j - m + 1]);
        }
    }

    sort(all(ans));
    cout << sz(ans) << endl;
    for(int x : ans)
        cout << x + 1 << " ";
    cout << endl;
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