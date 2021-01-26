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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
const int M = 15;
using namespace std;

vector<vector<int>> arr;
int n;

int dp[M][1 << M];

int solve(int i, bitset<M> mask)
{
    if(i == n)
        return 0;

    int &ret = dp[i][mask.to_ulong()];
    if(~ret)
        return ret;

    mask.flip();
    int msk = mask.to_ulong() & ((1 << n) - 1);
    mask.flip();

    int ans = 0;

    for(int submsk = msk; ; submsk = ((submsk - 1)&msk))
    {
        bitset<M> nmask(submsk);
        bool ok = true;
        int sum = 0;
        for(int j = 0; j < n && ok; j++)
        {
            if(nmask[j])
            {
                if((j + 1 < n && nmask[j + 1]) || (j + 1 < n && mask[j + 1]) || (j - 1 >= 0 && mask[j - 1]))
                    ok = false;
                sum += arr[i][j];
            }
        }
        if(ok)
            ans = max(ans, sum + solve(i + 1, nmask));
        if(!submsk)
            break;
    }
    return ret = ans;
}

void cp()
{
    string s;
    while(getline(cin, s))
    {
        vector<string> board(1, s);
        while(getline(cin, s) && !s.empty())
            board.pb(s);
        arr.clear();
        for(string x : board)
        {
            stringstream ss(x);
            vector<int> val;
            int xx;
            while(ss >> xx)
                val.pb(xx);
            arr.pb(val);
        }
        n = sz(arr);
        clr(dp, -1);
        cout << solve(0, 0) << endl;
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