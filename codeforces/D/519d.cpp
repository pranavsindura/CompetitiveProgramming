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

map<ll, int> cnt[26];

void cp()
{
    string s;
    vector<int> val(26);
    for(int &x : val)
        cin >> x;
    cin >> s;
    int n = ln(s);

    cnt[s[0] - 'a'][val[s[0] - 'a']]++;
    ll sum = val[s[0] - 'a'];
    ll ans = 0;

    for(int i = 1; i < n; i++)
    {
        if(cnt[s[i] - 'a'].count(sum))
            ans += cnt[s[i] - 'a'][sum];
        
        sum += val[s[i] - 'a'];
        cnt[s[i] - 'a'][sum]++;
    }

    cout << ans << endl;
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