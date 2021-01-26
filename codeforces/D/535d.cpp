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

int diff[MAXN];

int intersect(int a, int b, int c, int d)
{
    return max(0, min(b, d) - max(a, c) + 1);
}

void cp()
{
    // failure, diffarray, intersection length of ranges
    // check valid overlap
    int n, m;
    string p;
    cin >> n >> m >> p;
    vector<int> matches(m);
    for(int &x : matches)
        cin >> x, x--;

    vector<int> failure(ln(p));
    for(int i = 1, k = 0; i < ln(p); i++)
    {
        while(k && p[i] != p[k])
            k = failure[k - 1];
        if(p[i] == p[k])
            k++;
        failure[i] = k;
    }

    set<int> valid;
    int k = failure.back();
    valid.insert(k);
    while(k)
        k = failure[k - 1], valid.insert(k);

    ll ans = 1;
    for(int i = 0; i < sz(matches); i++)
    {
        int cur = matches[i];
        diff[cur]++, diff[cur + ln(p)]--;
        if(i)
        {
            int prev = matches[i - 1];
            int len = intersect(prev, prev + ln(p) - 1, cur, cur + ln(p) - 1);
            if(!valid.count(len))
                ans = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(i)
            diff[i] += diff[i - 1];
        if(!diff[i])
            ans = (ans * 26) % mod;
    }
    cout << ans << endl;
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