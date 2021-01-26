#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
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
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    string s;
    int k;
    cin >> s >> k;

    vector<char> v;
    for(char x = 'a'; x <= 'z'; x++)
        v.pb(x);

    int n = ln(s);
    vector<vector<int>> pos(26);

    for(int i = 0; i < n; i++)
    {
        pos[s[i] - 'a'].pb(i);
    }
    sort(all(v), [&](char a, char b)
    {
        return sz(pos[a - 'a']) < sz(pos[b - 'a']);
    });
    bool used[n];
    clr(used, false);
    for(int i = 0; i < 26 && k; i++)
    {
        for(int j = 0; j < sz(pos[v[i] - 'a']) && k; j++)
        {
            used[pos[v[i] - 'a'][j]] = true;
            k--;
        }
    }
    map<char, int> freq;
    int left = 0;
    string ans;
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
            freq[s[i]]++, ans += s[i];
    }
    cout << sz(freq) << endl << ans;
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