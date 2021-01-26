#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
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
const double PI = acos(-1.0);
int dp[4005][4005];
void cp()
{
    string a, b;
    cin >> a >> b;
    vector<vector<int>> pos(26);
    for(int i = 0; i < sz(a); i++)
    {
        pos[a[i] - 'a'].pb(i);
    }
    int prev = -1;
    int count = 1;
    bool ok = true;
    for(int i = 0; i < sz(b); i++)
    {
        if(sz(pos[b[i] - 'a']) == 0)
        {
            ok = false;
            break;
        }
        auto it = upper_bound(all(pos[b[i] - 'a']), prev);
        if(it != pos[b[i] - 'a'].end())
        {
            prev = *it;
        }
        else
        {
            count++;
            prev = pos[b[i] - 'a'][0];
        }
        // cout << b[i] - 'a' << " " << prev << " " << count << endl;
    }
    if(ok)
        cout << count;
    else
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