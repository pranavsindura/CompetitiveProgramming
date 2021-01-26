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

void cp()
{
    string s;
    cin >> s;
    int n = ln(s);
    vector<int> failure(n);
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k && s[i] != s[k])
            k = failure[k - 1];
        if(s[i] == s[k])
            k++;
        failure[i] = k;
    }
    int pos = -1;
    for(int i = 0; i < n; i++)
    {
        int rep = failure[i];
        if(rep && (i + 1) % (i + 1 - rep) == 0)
        {
            if((i + 1) / (i + 1 - rep) == 2)
                pos = i;
        }
    }
    assert(pos >= 0);

    int rep = pos + 1 - failure[pos];
    string t;
    for(int i = 0; i < rep; i++)
        t += s[i];
    int extra = n % rep;
    string ans;
    while(sz(ans) - extra <= 8)
        ans += t;
    reverse(all(ans));
    for(int i = 0; i < extra; i++)
        ans.pop_back();
    reverse(all(ans));
    while(sz(ans) > 8)
        ans.pop_back();
    cout << ans << "...\n";
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