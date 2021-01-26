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

int n, k;
bool check(int a, int b, int c)
{
    int need = k / 2;
    if(a > need)
        return false;
    if(b > need)
        return false;
    int aneed = need - a;
    if(c < aneed)
        return false;
    c -= aneed;
    int bneed = need - b;
    if(c < bneed)
        return false;
    c -= bneed;
    return (c == 0);
}

void cp()
{
    string s;
    cin >> n >> k >> s;
    bool ok = true;
    int one = 0, zero = 0, ques = 0;

    for(int i = k; i < n; i++)
    {
        if(s[i] != s[i - k])
        {
            if(s[i] == '?')
                s[i] = s[i - k];
            else if(s[i - k] == '?')
                s[i - k] = s[i];
            else
                ok = false;
        }
        // cout << zero << " " << one << " " << ques << endl;
        // dbg(ok);
    }
    // cout << s << endl;
    one = 0, zero = 0, ques = 0;
    for(int i = 0; i < k; i++)
        if(s[i] == '1')
            one++;
        else if(s[i] == '0')
            zero++;
        else
            ques++;
    if(!check(one, zero, ques))
        ok = false;
    for(int i = k; i < n; i++)
    {
        if(s[i] == '1')
            one++;
        else if(s[i] == '0')
            zero++;
        else
            ques++;
        if(s[i - k] == '1')
            one--;
        else if(s[i - k] == '0')
            zero--;
        else
            ques--;
        if(!check(one, zero, ques))
            ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
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