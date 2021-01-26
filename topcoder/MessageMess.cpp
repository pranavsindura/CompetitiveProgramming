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
const int MAXN = 1e6 + 5;

class MessageMess
{
public:
    string restore(vector<string> arr, string s)
    {
        map<string, bool> dict;
        for(string x : arr)
            dict[x] = true;
        int n = ln(s);
        s = " " + s;
        int dp[n + 1], last[n + 1];
        clr(dp, 0), clr(last, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            string temp;
            for(int j = i; j >= 1; j--)
            {
                temp = s[j] + temp;
                // find if temp is in dict
                if(dict.count(temp))
                    dp[i] += dp[j - 1], last[i] = j, dp[i] = min(dp[i], 2);;
            }
        }
        if(dp[n] == 0)
            return "IMPOSSIBLE!";
        else if(dp[n] > 1)
            return "AMBIGUOUS!";
        else
        {
            vector<string> res;
            int pos = n;
            while(pos)
            {
                string temp;
                for(int i = last[pos]; i <= pos; i++)
                    temp += s[i];
                res.pb(temp);
                pos = last[pos] - 1;
            }
            reverse(all(res));
            string ans;
            for(string x : res)
                ans += x + " ";
            ans.pop_back();
            return ans;
        }
    }
};