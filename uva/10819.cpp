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
int dp[105][10205];
int n, budget;
vector<pi> item;
int rec(int i, int w)
{
	//exceeding budget is okay
	//but if the excess is > 200 i.e. the max refund you get, you can't buy this item even if you get the refund
	//so skip it
    if(w > budget && w - budget > 200)
        return -100000;
    if(i == n)
    {
    	//now you can't exceed budget, as the final item decided if refund is applicable or not.
    	//but still according to previous conditions it may exceed budget and the excess will be <= 200
    	//but what if refund is still not applicable?
    	//if money you spent(w) <= 2000 you get no refund
        if(w > budget && w <= 2000)
            return -100000;
        //If it does not exceed you're okay!
        //If it exceeds, you get refund and w <= budget+200, still okay!
        else
            return 0;
    }
    if(~dp[i][w])
        return dp[i][w];
    return dp[i][w] = max(rec(i + 1, w), rec(i + 1, w + item[i].ff) + item[i].ss);
}

void cp()
{
    while(cin >> budget >> n)
    {
        clr(dp, -1);
        item.clear();
        for(int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            item.pb({a, b});
        }
        cout << rec(0, 0) << endl;
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