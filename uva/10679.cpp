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
    string s;
    int q;
    cin >> s >> q;
    int n = ln(s);
    while(q--)
    {
        string pat;
        cin >> pat;
        int m = ln(pat);
        vector<int> failure(m);
        for(int i = 1, k = 0; i < m; i++)
        {
            while(k && pat[i] != pat[k])
                k = failure[k - 1];
            if(pat[i] == pat[k])
                k++;
            failure[i] = k;
        }
        bool found = false;
        for(int i = 0, k = 0; i < n; i++)
        {
            while(k && s[i] != pat[k])
                k = failure[k - 1];
            if(s[i] == pat[k])
                k++;
            if(k == m)
                found = true, k = failure[k - 1];
        }
        cout << (found ? "y\n" : "n\n");
    }
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