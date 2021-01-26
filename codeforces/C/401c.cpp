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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    bool found = false;
    string ans;

    for(int i = 0; i <= n && ans.empty(); i++)
    {
        // i group of (1, 2) split
        int rem_zero = n - i, rem_one = m - 2 * i;

        // make (1, 1) split of the rest
        int group = min(rem_zero, rem_one);
        rem_zero -= group, rem_one -= group;

        if(!rem_one && !rem_zero)
        {
            for(int j = 0; j < i; j++)
                ans += "110";
            for(int j = 0; j < group; j++)
                ans += "10";
        }
        else if(rem_one)
        {
            if(rem_one <= 2)
            {
                for(int j = 0; j < i; j++)
                    ans += "110";
                for(int j = 0; j < group; j++)
                    ans += "10";
                ans += string(rem_one, '1');
            }
        }
        else
        {
            if(rem_zero == 1)
            {
                ans += "0";
                for(int j = 0; j < i; j++)
                    ans += "101";
                for(int j = 0; j < group; j++)
                    ans += "10";
            }
            else if(rem_zero == 2 && i)
            {
                ans += "0";
                for(int j = 0; j < i; j++)
                    ans += "101";
                ans += "0";
                for(int j = 0; j < group; j++)
                    ans += "10";
            }
        }
    }

    if(!ans.empty())
        cout << ans << endl;
    else
        cout << -1 << endl;
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