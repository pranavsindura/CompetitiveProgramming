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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int mn = INT_MAX;
    string ans = s;
    map<char, int> cnt;
    for(char x : s)
        cnt[x]++;
    for(char c = '0'; c <= '9'; c++)
    {
        string t = s;
        int op = 0;
        int need = max(0, k - cnt[c]);
        int cost = 0;
        for(int j = 1; j < 10; j++)
        {
            char d = c + j;
            if(d <= '9')
            {
                for(int i = 0; i < n && op < need; i++)
                {
                    if(t[i] == d)
                    {
                        t[i] = c;
                        op++;
                        cost += int(d - c);
                    }
                }
            }
            d = c - j;
            if(d >= '0')
            {
                for(int i = n - 1; i >= 0 && op < need; i--)
                {
                    if(t[i] == d)
                    {
                        t[i] = c;
                        op++;
                        cost += int(c - d);
                    }
                }
            }
        }
        if(op == need && (cost < mn || (cost == mn && t < ans)))
            mn = cost, ans = t;
    }
    cout << mn << endl << ans;
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