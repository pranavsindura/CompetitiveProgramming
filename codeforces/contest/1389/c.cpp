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
    string s;
    cin >> s;
    int n = ln(s);
    int ans = n - 2;
    for(char a = '0'; a <= '9'; a++)
    {
        for(char b = '0'; b <= '9'; b++)
        {
            if(a == b)
                continue;
            string c;
            c += a, c += b;
            int p = 0;
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(c[p] == s[i])
                    cnt++, p ^= 1;
            }
            if(cnt & 1)
                cnt--;
            ans = min(ans, n - cnt);
        }
    }
    for(char b = '0'; b <= '9'; b++)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(b == s[i])
                cnt++;
        }
        ans = min(ans, n - cnt);
    }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}