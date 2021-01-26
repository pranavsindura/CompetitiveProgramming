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
    ll n, k;
    cin >> n >> k;
    int arr[n + 1];
    for(int i = 0; i < n; i++)
        cin >> arr[i + 1];
    bool vis[n + 1];
    clr(vis, false);
    ll cycle_len = 0;
    int town = 1;
    int cycle[n + 5];
    while(!vis[town])
    {
        cycle[cycle_len] = town;
        vis[town] = true;
        town = arr[town];
        cycle_len++;
    }
    int pos = 0;
    for(int i = 0; i < n + 5; i++)
    {
        if(cycle[i] == town)
        {
            pos = i;
            break;
        }
    }
    if(k > pos)
    {
        cout << cycle[pos + (k - pos) % (cycle_len - pos)];
    }
    else
        cout << cycle[k];
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