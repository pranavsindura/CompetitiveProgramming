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
    string s;
    int k;
    cin >> s >> k;
    int n = ln(s);
    string w(n, '*');
    bool ok = true;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0')
        {
            if(i - k >= 0)
            {
                w[i - k] = '0';
                if(i + k < n)
                    w[i + k] = '0';
            }
            else if(i + k < n)
            {
                w[i + k] = '0';
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            if(i - k >= 0)
            {
                if(w[i - k] == '*' || w[i - k] == '1')
                    w[i - k] = '1';
                else
                {
                    if(i + k < n)
                    {
                        if(w[i + k] == '*' || w[i + k] == '1')
                            w[i + k] = '1';
                        else
                            ok = false;
                    }
                    else
                        ok = false;
                }
            }
            else if(i + k < n)
            {
                if(w[i + k] == '*' || w[i + k] == '1')
                    w[i + k] = '1';
                else
                    ok = false;
            }
            else
                ok = false;
        }
    }
    for(char &x : w)
        if(x == '*')
            x = '0';
    if(ok)
        cout << w << endl;
    else
        cout << -1 << endl;
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