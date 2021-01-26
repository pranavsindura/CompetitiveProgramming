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
    cin >> s;
    // failure, prefix count, exist
    int n = ln(s);
    vector<int> failure(n), prefix_count(n);
    vector<bool> exist(n);

    for(int i = 1, k = 0; i < n; i++)
    {
        while(k && s[i] != s[k])
            k = failure[k - 1];
        if(s[i] == s[k])
            k++;
        failure[i] = k;
    }

    for(int i = n - 1; i >= 0; i--)
        if(failure[i])
            prefix_count[failure[i] - 1] += prefix_count[i] + 1;

    int ans = 1;
    int k = failure[n - 1];
    while(k)
        ans++, exist[k - 1] = true, k = failure[k - 1];
    exist[n - 1] = true;
    
    cout << ans << endl;
    for(int i = 0; i < n; i++)
        if(exist[i])
            cout << i + 1 << " " << prefix_count[i] + 1 << endl;
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