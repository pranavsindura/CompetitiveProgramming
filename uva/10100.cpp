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

string clean(string &s)
{
    for(char &c : s)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {

        }
        else
            c = ' ';
    }
    string ans;
    string temp;
    for(char c : s)
    {
        if(c == ' ')
        {
            if(ln(temp))
                ans += temp, ans += " ", temp = "";
        }
        else
            temp += c;
    }
    if(ln(temp))
        ans += temp + " ";
    if(ln(ans))
        ans.pop_back();
    return ans;
}

int dp[1005][1005];

int solve(int i, int j, vector<string> &a, vector<string> &b)
{
    if(i == sz(a) || j == sz(b))
        return 0;

    int &ret = dp[i][j];
    if(~ret)
        return ret;

    if(a[i] == b[j])
        return ret = 1 + solve(i + 1, j + 1, a, b);
    else
        return ret = max(solve(i + 1, j, a, b), solve(i, j + 1, a, b));
}

void cp()
{
    int test = 1;
    string x, y;
    while(getline(cin, x) && getline(cin, y))
    {
        cout << setw(2) << right << test++ << ". ";
        x = clean(x);
        y = clean(y);
        if(x.empty() || y.empty())
        {
            cout << "Blank!\n";
            continue;
        }
        vector<string> a, b;
        stringstream ss1(x);
        while(!ss1.eof())
        {
            string temp;
            ss1 >> temp;
            a.pb(temp);
        }
        stringstream ss2(y);
        while(!ss2.eof())
        {
            string temp;
            ss2 >> temp;
            b.pb(temp);
        }

        clr(dp, -1);
        int ans = solve(0, 0, a, b);
        cout << "Length of longest match: " << ans << endl;
    }

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