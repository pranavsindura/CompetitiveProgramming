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

class IdealString
{
public:
    int dp[105][105];
    int n;
    bool check(int i, int d)
    {
        if(i > n)
            return d == 0;

        int &ret = dp[i][d];
        if(~ret)
            return ret;

        bool c1 = false, c2 = false;
        if(d - 1 >= 0)
            c1 = check(i + 1, d - 1);
        if(d + i - 1 >= 0 && d + i - 1 <= n - i)
            c2 = check(i + 1, d + i - 1);
        return ret = c1 | c2;
    }

    string construct(int len)
    {
        // len = 12
        // my -  ABCBCDCDDDDD
        //       ABC**D******
        // ans - ABBCDCCCDDDD
        string res;
        clr(dp, -1);
        n = len;

        bool ok = true;
        int cnt[26] = {0};
        int extra = 0;
        int place = 0;

        for(int p = 1; p <= n; p++)
        {
            bool found = false;
            for(int i = 0; i < place; i++)
            {
                // place an old char
                if(cnt[i] > 0 && check(p + 1, extra - 1))
                {
                    res += char(65 + i);
                    cnt[i]--;
                    extra--;
                    found = true;
                    break;
                }
            }
            if(found)
                continue;
            // place new char
            if(check(p + 1, extra + p - 1))
            {
                res += char(65 + place);
                cnt[place] = p - 1;
                extra += p - 1;
                place++;
            }
            else
                ok = false;
        }
        return ok ? res : "";
    }
};

int main()
{
    IdealString s;
    // int len;
    // cin >> len;
    for(int i = 1; i <= 100; i++)
        cout << s.construct(i) << endl;
    return 0;
}
