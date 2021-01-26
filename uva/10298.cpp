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

string s;
vector<int> longest_prefix;
void cp()
{
    int n = ln(s);
    longest_prefix.resize(n);
    longest_prefix[0] = 0;
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k && s[i] != s[k])
            k = longest_prefix[k - 1];
        if(s[i] == s[k])
            k++;
        longest_prefix[i] = k;
    }
    int rep = longest_prefix.back();
    int ans = 1;
    if(rep && n % (n - rep) == 0)
        ans = n / (n - rep);
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> s && s[0] != '.')
    {
        cp();
    }
    return 0;
}