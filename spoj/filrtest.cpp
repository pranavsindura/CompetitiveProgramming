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

int k;
string str;

vector<int> compute_prefix()
{
    int n = ln(str);
    vector<int>longest_prefix(n);
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k > 0 && str[i] != str[k])
            k = longest_prefix[k - 1];
        if(str[i] == str[k])
            longest_prefix[i] = ++k;
        else
            longest_prefix[i] = k;
    }
    return longest_prefix;
}

void cp()
{
    vector<int> longest_prefix = compute_prefix();
    int most = longest_prefix.back();
    int ans = 0;
    if(k >= ln(str))
        ans = 1 + (k - ln(str)) / (ln(str) - most);
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> k >> str && ~k)
    {
        cp();
    }
    return 0;
}