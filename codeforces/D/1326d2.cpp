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

string s;

string longest_prefix(string &t)
{
    string revt = t;
    reverse(all(revt));
    string pat = t + "#" + revt;

    vector<int> failure(ln(pat));
    for(int i = 1, k = 0; i < ln(pat); i++)
    {
        while(k && pat[i] != pat[k])
            k = failure[k - 1];
        if(pat[i] == pat[k])
            k++;
        failure[i] = k;
    }
    string res;
    for(int i = 0; i < failure.back(); i++)
        res += pat[i];
    return res;
}



void cp()
{
    cin >> s;
    int n = ln(s);
    pi best = {-1, n};
    int i = 0, j = n - 1;
    while(s[i] == s[j] && i < j)
    {
        best = {i, j};
        i++, j--;
    }

    string pref, suff, mid;
    for(int i = 0; i <= best.ff; i++)
        pref += s[i];
    suff = pref;
    reverse(all(suff));

    string mid_pat;
    for(int i = best.ff + 1; i < best.ss; i++)
        mid_pat += s[i];

    mid = longest_prefix(mid_pat);
    reverse(all(mid_pat));
    string other = longest_prefix(mid_pat);
    if(ln(other) > ln(mid))
        mid = other;

    cout << pref + mid + suff << endl;
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