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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);
int n, k;
vector<string> arr(2005);
vector<string> seg = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int cost[2005][10];
int dp[2005][2005];
int val(int i, int j)
{
    int c = 0;
    for(int bit = 0; bit < 7; bit++)
    {
        if(arr[i][bit] == '1' && seg[j][bit] == '0')
            return INT_MAX;
        else if(arr[i][bit] == '0' && seg[j][bit] == '1')
            c++;
        else if(arr[i][bit] == '1' && seg[j][bit] == '1')
        {
            //ok
        }
        else
        {
            //ok
        }
    }
    return c;
}
vector<int> ans;
bool solve(int i, int rem)
{
    int &ret = dp[i][rem];
    if(ret != -1)
        return ret;
    if(i == n)
    {
        return ret = rem == 0;
    }
    else
    {
        for(int j = 9; j >= 0; j--)
        {
            if(cost[i][j] <= rem)
            {
                ans.pb(j);
                if(solve(i + 1, rem - cost[i][j]))
                    return ret = true;
                ans.pop_back();
            }
        }
    }
    return ret = false;
}

void cp()
{
    clr(dp, -1);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= 9; j++)
            cost[i][j] = val(i, j);

    bool ok = solve(0, k);
    if(ok)
    {
        for(int x : ans)
            cout << x;
    }
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