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
const int MAXN = 2e6 + 5;

/*
	We are given n palindromes
	Two palindromes when connected together give another palindrome
	if their repeating element/block is same
*/

map<string, int> cnt;
vector<int> longest_prefix(MAXN);
string s;
int m;

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> m >> s;
        fill(begin(longest_prefix), begin(longest_prefix) + m + 1, 0);
        for(int j = 1, k = 0; j < m; j++)
        {
            while(k > 0 && s[j] != s[k])
                k = longest_prefix[k - 1];
            if(s[j] == s[k])
                longest_prefix[j] = ++k;
            else
                longest_prefix[j] = k;
        }
        int rep = m;
        if(m % (m - longest_prefix[m - 1]) == 0)
            rep = m - longest_prefix[m - 1];
        string t;
        for(int j = 0; j < rep; j++)
            t += s[j];
        // cout << t << endl;
        cnt[t]++;
    }
    ll ans = 0;
    for(auto &x : cnt)
        ans += x.ss * 1LL * x.ss;
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