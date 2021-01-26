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

vector<int> longest_prefix(string &pat)
{
    int n = ln(pat);
    vector<int> failure(n);
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k && pat[i] != pat[k])
            k = failure[k - 1];
        if(pat[i] == pat[k])
            k++;
        failure[i] = k;
    }
    return failure;
}

void cp()
{
    string s, t;
    cin >> s >> t;
    vector<int> cnt(2);
    for(char x : s)
        cnt[x - '0']++;

    vector<int> failure = longest_prefix(t);
    vector<int> need(2);
    for(char x : t)
        need[x - '0']++;

    string ans;

    if(cnt[0] >= need[0] && cnt[1] >= need[1])
    {
        int fallback = failure.back();
        int i = 0;
        while(true)
        {
            if(cnt[t[i] - '0'] > 0)
                ans += t[i], cnt[t[i] - '0']--;
            else
                break;
            i++;
            if(i == ln(t))
                i = fallback;
        }
        for(i = 0; i < cnt[0]; i++)
            ans += '0';
        for(i = 0; i < cnt[1]; i++)
            ans += '1';
    }
    else
        ans = s;

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