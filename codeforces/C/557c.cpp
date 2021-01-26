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
const int MAXN = 1e5 + 5;

int len[MAXN];
int freq[MAXN];
int costs[MAXN];

int have[205];
vector<int> each[MAXN];

void cp()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> len[i], freq[len[i]]++;
    int totalcost = 0;
    for(int i = 0, x; i < n; i++)
        cin >> x, costs[len[i]] += x, totalcost += x, each[len[i]].pb(x);

    int sofar = 0;
    int ans = INT_MAX;
    for(int i = 1; i < MAXN; i++)
    {
        if(!freq[i])
            continue;
        totalcost -= costs[i];
        sofar += freq[i];
        int k = min(sofar, 2 * freq[i] - 1);
        int rem = sofar - k;
        int me = totalcost;
        int pos = 0;
        while(rem > 0 && pos < 205)
        {
            int x = min(have[pos], rem);
            rem -= x;
            me += pos * x;
            pos++;
        }
        for(int x : each[i])
            have[x]++;
        // cout << i << ": " << me << endl;
        ans = min(ans, me);
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