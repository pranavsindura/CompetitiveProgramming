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

bool check_palin(string &s)
{
    for(int i = 0; i < ln(s) / 2; i++)
        if(s[i] != s[ln(s) - i - 1])
            return false;
    return true;
}

void cp()
{
    string s;
    cin >> s;
    string pat = s;
    s += s;
    reverse(all(pat));

    int n = ln(s), m = ln(pat);
    vector<int> failure(m);
    for(int i = 1, k = 0; i < m; i++)
    {
        while(k && pat[i] != pat[k])
            k = failure[k - 1];
        if(pat[i] == pat[k])
            k++;
        failure[i] = k;
    }
    bool is_palin = check_palin(pat);
    vector<int> matches;
    for(int i = 0, k = 0; i < n; i++)
    {
        while(k && s[i] != pat[k])
            k = failure[k - 1];
        if(s[i] == pat[k])
            k++;
        if(k == m)
            matches.pb(i - m + 1), k = failure[k - 1];
    }
    if(is_palin)
    {
        if(sz(matches) > 2)
            cout << "alindrome\n";
        else
            cout << "palindrome\n";
    }
    else if(!matches.empty())
        cout << "alindrome\n";
    else
        cout << "simple\n";
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