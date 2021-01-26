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

ll a, b, c;
bool like[7][7];
map<string, int> idx;

void init()
{
    vector<string> name = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
    for(int i = 0; i < sz(name); i++)
        idx[name[i]] = i;
}

ll min_diff = INT_MAX, max_like;

void solve(int i, vector<int> cnt_a, vector<int> cnt_b, vector<int> cnt_c)
{
    if(i == 7)
    {
        if(cnt_a.empty() || cnt_b.empty() || cnt_c.empty())
            return;
        // first find the exp gained
        ll sz_a = sz(cnt_a);
        ll sz_b = sz(cnt_b);
        ll sz_c = sz(cnt_c);

        ll exp_a = a / sz_a;
        ll exp_b = b / sz_b;
        ll exp_c = c / sz_c;

        ll max_exp = max({exp_a, exp_b, exp_c});
        ll min_exp = min({exp_a, exp_b, exp_c});
        ll min_diff_here = max_exp - min_exp;

        ll like_a = 0;
        ll like_b = 0;
        ll like_c = 0;

        for(int p : cnt_a)
            for(int q : cnt_a)
                like_a += like[p][q];

        for(int p : cnt_b)
            for(int q : cnt_b)
                like_b += like[p][q];

        for(int p : cnt_c)
            for(int q : cnt_c)
                like_c += like[p][q];

        ll like_here = like_a + like_b + like_c;

        if((min_diff_here < min_diff) || (min_diff_here == min_diff && like_here > max_like))
        {
            min_diff = min_diff_here, max_like = like_here;
        }

    }
    else
    {
        cnt_a.pb(i);
        solve(i + 1, cnt_a, cnt_b, cnt_c);
        cnt_a.pop_back();

        cnt_b.pb(i);
        solve(i + 1, cnt_a, cnt_b, cnt_c);
        cnt_b.pop_back();

        cnt_c.pb(i);
        solve(i + 1, cnt_a, cnt_b, cnt_c);
        cnt_c.pop_back();
    }
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string u, temp, v;
        cin >> u >> temp >> v;
        like[idx[u]][idx[v]] = true;
    }
    cin >> a >> b >> c;
    solve(0, vector<int>(), vector<int>(), vector<int>());
    cout << min_diff << " " << max_like;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}