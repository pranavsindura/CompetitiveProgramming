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
#define dbg(x) cout<<#x<<" "<<x<<endl
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
    cin >> s;
    int m;
    int n = ln(s);
    cin >> m;
    bool forb[26][26] = {0};
    for(int i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        int a = x[0] - 'a';
        int b = x[1] - 'a';
        forb[a][b] = true;
        forb[b][a] = true;
    }
    vector<string> reduced;
    string temp;
    temp += s[0];
    for(int i = 1; i < n; i++)
    {
        int a = s[i - 1] - 'a';
        int b = s[i] - 'a';
        if(a == b || forb[a][b])
        {
            temp += s[i];
        }
        else
        {
            reduced.pb(temp);
            temp = "";
            temp += s[i];
        }
    }
    reduced.pb(temp);

    int ans = 0;
    for(string &x : reduced)
    {
    	// cout<<x<<"|";
        map<char, int> freq;
        for(char xx : x)
            freq[xx]++;
        if(sz(freq) <= 1)
            continue;
        else
        {
            int mn = INT_MAX;
            for(auto &f : freq)
                mn = min(mn, f.ss);
            ans += mn;
        }
    }
    cout<<ans;
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