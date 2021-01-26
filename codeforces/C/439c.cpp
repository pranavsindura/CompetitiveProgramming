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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void no()
{
    cout << "NO\n";
    exit(0);
}

void cp()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> odd, even;
    vector<vector<int>> odd_ans, even_ans;
    for(int i = 0, x = 0; i < n; i++)
    {
        cin >> x;
        if(x & 1)
            odd.pb(x);
        else
            even.pb(x);
    }
    if(k - p > sz(odd))
        no();
    else
    {
        for(int i = 0; i < k - p; i++)
            odd_ans.pb({odd.back()}), odd.pop_back();
        if(sz(even) + sz(odd) / 2 < p)
            no();
        else
        {
            while(sz(odd) > 1 && sz(even_ans) < p)
            {
                even_ans.pb(vector<int>());
                even_ans.back().pb(odd.back());
                odd.pop_back();
                even_ans.back().pb(odd.back());
                odd.pop_back();
            }

            while(sz(even) && sz(even_ans) < p)
            {
                even_ans.pb({even.back()});
                even.pop_back();
            }
        }
    }

    if(sz(odd) & 1)
        no();
    if(p)
    {
        while(!even.empty())
            even_ans.back().pb(even.back()), even.pop_back();
        while(!odd.empty())
            even_ans.back().pb(odd.back()), odd.pop_back();
    }
    else
    {
        while(!even.empty())
            odd_ans.back().pb(even.back()), even.pop_back();
        while(!odd.empty())
            odd_ans.back().pb(odd.back()), odd.pop_back();
    }
    cout << "YES\n";
    for(auto &v : even_ans)
    {
        cout << sz(v) << " ";
        for(int x : v)
            cout << x << " ";
        cout << endl;
    }
    for(auto &v : odd_ans)
    {
        cout << sz(v) << " ";
        for(int x : v)
            cout << x << " ";
        cout << endl;
    }
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