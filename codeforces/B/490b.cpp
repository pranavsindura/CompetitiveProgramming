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

void cp()
{
    int n, a, b;
    cin >> n;
    set<pair<int, int>> arr;
    map<int, bool> start, end;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr.insert(mp(a, b));
        start[a] = true;
        end[b] = true;
    }
    vector<int> ans(n);
    for(pair<int, bool> x : start)
    {
        if(!end[x.ff])
            ans[0] = x.ff;
    }
    for(pair<int, int> x : arr)
    {
        if(x.ff == 0)
            ans[1] = x.ss;
    }
    for(int i = 2; i < n; i++)
    {
        int to_find = ans[i - 2];
        auto it = arr.lower_bound(mp(to_find, 0));
        ans[i] = it->ss;
    }
    for(int x: ans)
    	cout<<x<<" ";
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