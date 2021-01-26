#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    char arr[n][n];
    bool done[n][n];
    clr(done, false);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    bool ok = true;
    vector<pi> spells;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == '.')
            {
                // cast spell
                spells.pb({i + 1, j + 1});
                break;
            }
        }
    }
    if(sz(spells) == n)
    {
        for(pi x : spells)
            cout << x.ff << " " << x.ss << endl;
        return;
    }
    spells.clear();
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(arr[i][j] == '.')
            {
                // cast spell
                spells.pb({i + 1, j + 1});
                break;
            }
        }
    }
    if(sz(spells) == n)
    {
        for(pi x : spells)
            cout << x.ff << " " << x.ss << endl;
        return;
    }
    cout << -1;
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