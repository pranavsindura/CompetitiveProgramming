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

bool palin(string &s, int l, int r)
{
    if(s.empty())
        return false;
    int n = (r - l + 1);
    for(int i = 0; i < n / 2; i++)
        if(s[l + i] != s[l + (n - i - 1)])
            return false;
    return true;
}

void cp()
{
    string s;
    cin >> s;
    int n = ln(s);
    // both prefix and suffix
    int mx = 1;
    pi best = {0, n};

    for(int i = 0; i < n; i++)
    {
        pi me = {-1, n};
        int l = 0, r = n - 1;
        while(s[l] == s[r] && l <= i && r > i)
        {
            me = {l, r};
            l++, r--;
        }
        string temp;
        for(int j = 0; j <= i; j++)
            temp += s[j];
        for(int j = me.ss; j < n; j++)
            temp += s[j];
        if(palin(temp, 0, ln(temp) - 1))
        {
            int len = ln(temp);
            if(len > mx)
                mx = len, best = {i, me.ss};
        }
    }

    for(int i = n - 1; i >= 0; i--)
    {
        pi me = {-1, n};
        int l = 0, r = n - 1;
        while(s[l] == s[r] && l < i && r >= i)
        {
            me = {l, r};
            l++, r--;
        }
        string temp;
        for(int j = 0; j <= me.ff; j++)
            temp += s[j];
        for(int j = i; j < n; j++)
            temp += s[j];
        if(palin(temp, 0, ln(temp) - 1))
        {
            int len = ln(temp);
            if(len > mx)
                mx = len, best = {me.ff, i};
        }
    }

    // only prefix
    for(int i = 0; i < n; i++)
    {
        if(palin(s, 0, i))
        {
            int len = i + 1;
            if(len > mx)
                mx = len, best = {i, n};
        }
    }

    // only suffix
    for(int i = n - 1; i >= 0; i--)
    {
        if(palin(s, i, n - 1))
        {
            int len = n - i;
            if(len > mx)
                mx = len, best = {-1, i};
        }
    }

    string ans;
    for(int i = 0; i <= best.ff; i++)
        ans += s[i];
    for(int i = best.ss; i < n; i++)
        ans += s[i];
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