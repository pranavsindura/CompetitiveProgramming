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
const double eps = 1e-8;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

void cp()
{
    int n, w, m;
    cin >> n >> w >> m;

    dblout(10);
    if(m > 2 * n)
    {
        cout << "NO\n";
        return;
    }

    double each = double(n * w) / double(m);

    double have = 0;
    vector<double> milk(n, w);
    vector<vector<pair<int, double>>> ans(1);

    bool excess = false;
    vector<int> freq(n + 1);

    while(sz(ans) <= m && !milk.empty())
    {
        double last = milk.back();
        milk.pop_back();
        double need = each - have;


        if(freq[sz(milk) + 1] >= 2)
            excess = true;

        if(dcmp(need, last) > 0)
        {
            ans.back().pb({sz(milk) + 1, last});
            have += last;
        }
        else
        {
            last -= need;
            ans.back().pb({sz(milk) + 1, need});
            freq[sz(milk) + 1]++;
            ans.pb(vector<pair<int, double>>());
            if(dcmp(last, 0) > 0)
                milk.pb(last);
            have = 0;
        }
    }

    if(sz(ans) <= m || excess)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(auto &v : ans)
        {
            while(!v.empty())
            {
                auto x = v.back();
                v.pop_back();
                while(!v.empty() && v.back().ff == x.ff)
                    x.ss += v.back().ss, v.pop_back();
                cout << x.ff << " " << x.ss << " ";
            }
            cout << endl;
        }
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