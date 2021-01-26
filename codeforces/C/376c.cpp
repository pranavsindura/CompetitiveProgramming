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
const int MAXN = 1e6 + 5;

vector<string> opt =
{
    "1869",
    "1896",
    "9168",
    "1698",
    "6198",
    "1689",
    "6189"
};
void cp()
{
    string s;
    cin >> s;
    string ans, zero;
    int sum = 0, p = 10000 % 7;

    vector<bool> picked(10);
    for(char x : s)
    {
        if(x == '0')
            zero += x;
        else if(x == '1' || x == '6' || x == '8' || x == '9')
        {
            if(!picked[x - '0'])
                picked[x - '0'] = 1;
            else
                ans += x, sum = (sum + p * (x - '0')) % 7, p = (p * 10) % 7;
        }
        else
            ans += x, sum = (sum + p * (x - '0')) % 7, p = (p * 10) % 7;

    }
    reverse(all(ans));
    ans += opt[sum];
    ans += zero;
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