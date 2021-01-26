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

bool open(char x)
{
    return (x == '(' || x == '[');
}

char flip(char x)
{
    if(x == '(')
        return ')';
    else if(x == ')')
        return '(';
    else if(x == '[')
        return ']';
    else
        return '[';
}

int dp[105][105];

string s;
int solve(int i, int j)
{
    if(i > j)
        return 0;
    if(i == j)
        return 1;

    int &ret = dp[i][j];
    if(~ret)
        return ret;

    int ans = 500;

    if(s[i] == flip(s[j]) && open(s[i]))
        ans = min(ans, solve(i + 1, j - 1));

    for(int k = i; k < j; k++)
        ans = min(ans, solve(i, k) + solve(k + 1, j));

    return ret = ans;
}

string trace(int i, int j)
{
    if(i > j)
        return "";

    if(i == j)
    {
        if(open(s[i]))
            return string(1, s[i]) + flip(s[i]);
        else
            return string(1, flip(s[i])) + s[i];
    }

    int best = solve(i, j);

    if(s[i] == flip(s[j]) && open(s[i]))
    {
        int c = solve(i + 1, j - 1);
        if(c == best)
            return string(1, s[i]) + trace(i + 1, j - 1) + string(1, s[j]);
    }

    for(int k = i; k < j; k++)
    {
        int c = solve(i, k) + solve(k + 1, j);
        if(c == best)
            return trace(i, k) + trace(k + 1, j);
    }
    return "NOT FOUND LOL SCAM";
}

void cp()
{
    cin.ignore();
    getline(cin, s);
    clr(dp, -1);
    int ops = solve(0, ln(s) - 1);
    string seq = trace(0, ln(s) - 1);
    cout << seq << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        cp();
        if(t)
            cout << endl;
    }
    return 0;
}