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

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = INT_MAX;
    int r = 0, b = 0;
    for(char x : s)
        if(x == 'r')
            r++;
        else
            b++;

    // rbrbrbrb
    int cr = 0, cb = 0;
    for(int i = 0; i < n; i++)
    {
        if(i & 1)
        {
            // should be b
            if(s[i] == 'b')
                continue;
            else
                cb++;

        }
        else
        {
            // should be r
            if(s[i] == 'r')
                continue;
            else
                cr++;
        }
    }
    int common = min(cb, cr);
    int left = cb + cr - 2 * common;
    ans = min(ans, common + left);


    cr = 0, cb = 0;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            // should be b
            if(s[i] == 'b')
                continue;
            else
                cb++;

        }
        else
        {
            // should be r
            if(s[i] == 'r')
                continue;
            else
                cr++;
        }
    }
    common = min(cb, cr);
    left = cb + cr - 2 * common;
    ans = min(ans, common + left);

    cout << ans;
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