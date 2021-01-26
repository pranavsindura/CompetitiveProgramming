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

void cp()
{
    string s, t;
    cin >> s >> t;
    int n = ln(s), m = ln(t);

    bool ok = n >= m;

    t = t + "#";
    int i = 0, j = 0;
    map<char, int> exist;
    vector<int> left(n), right(n);
    while(i < n && ok)
    {
        if(s[i] == t[j])
            left[i] = exist[t[j]] = j++;
        else if(exist.count(s[i]))
            left[i] = exist[s[i]];
        else
            ok = false;
        i++;
    }
    t.pop_back();
    exist.clear();

    t = "#" + t;
    i = n - 1, j = m;
    while(i >= 0 && ok)
    {
        if(s[i] == t[j])
            right[i] = exist[t[j]] = --j;
        else if(exist.count(s[i]))
            right[i] = exist[s[i]];
        else
            ok = false;
        i--;
    }

    for(int i = 0; i < n; i++)
        ok &= (left[i] >= right[i]);

    cout << (ok ? "Yes\n" : "No\n");
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