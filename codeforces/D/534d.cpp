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
const int MAXN = 2e5 + 5;
vector<vector<int>> pos(MAXN);
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos[x].pb(i + 1);
    }
    vector<int> ans;
    bool ok = true;
    int people = 0;
    int l = 0, r = 0;
    while(r < n && ok)
    {
        // can satisfy req of amount = people
        while(pos[people].empty() && ok)
        {
            l += 3, people -= 3;
            if(l > r)
                ok = false;
        }
        if(!ok)
            break;
        // take one of the people
        ans.pb(pos[people].back());
        pos[people].pop_back();
        people++;
        r++;
    }

    if(ok)
    {
        cout << "Possible\n";
        for(int x : ans)
            cout << x << " ";
    }
    else
        cout << "Impossible\n";
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