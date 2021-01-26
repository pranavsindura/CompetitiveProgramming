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

bool match(string &s, string &pat, int i)
{
    bool ok = true;
    for(int j = 0; j < sz(pat); j++)
        if(s[i + j] != pat[j] && s[i + j] != '?')
            ok = false;
    return ok;
}

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    string pat = "abacaba";
    for(int i = 0; i + sz(pat) - 1 < n; i++)
    {
        bool ok = match(s, pat, i);
        if(ok)
        {
            string temp = s;
            for(int j = 0; j < sz(pat); j++)
                if(temp[i + j] == '?')
                    temp[i + j] = pat[j];
            for(char &x : temp)
                if(x == '?')
                    x = 'z';

            int count = 0;
            for(int j = 0; j + sz(pat) - 1 < n; j++)
                if(match(temp, pat, j))
                    count++;
            if(count == 1)
            {
                cout << "YES\n";
                cout << temp << endl;
                return;
            }
        }
    }
    cout << "NO\n";
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