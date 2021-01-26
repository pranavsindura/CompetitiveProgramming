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

void cp()
{
    int n, q;
    cin >> n >> q;
    ll black = (n - 2) * 1LL * (n - 2);
    set<int> row, col;
    row.insert(n), col.insert(n);
    vector<bool> donerow(n + 1), donecol(n + 1);
    while(q--)
    {
        int t, x;
        cin >> t >> x;
        if(t == 1)
        {
            if(donecol[x])
                continue;
            int first = *row.lower_bound(x);
            black -= first - 2;
            donecol[x] = 1;
            col.insert(x);
        }
        else
        {
            if(donerow[x])
                continue;
            int first = *col.lower_bound(x);
            black -= first - 2;
            donerow[x] = 1;
            row.insert(x);
        }
    }
    cout << black << endl;
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