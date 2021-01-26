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
    string ans = s;
    for(int i = 0; i < n; i++)
    {
        int need = 10 - (s[i] - '0');
        need %= 10;
        string temp;
        for(int j = 0; j < n; j++)
        {
            int num = s[j] - '0';
            num = (num + need) % 10;
            temp += char(48 + num);
        }
        // shift to bring ith position to zero;
        string cur;
        for(int j=0;j<n;j++)
        	cur += temp[(j+i)%n];
        ans = min(ans, cur);
    }
    cout<<ans;
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