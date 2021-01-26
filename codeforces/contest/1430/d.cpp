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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> start;
    set<pi> len;

    int l = 0, r = 0;
    while(l < n)
    {
        r = l;
        while(r + 1 < n && s[r + 1] == s[l])
            r++;
        start.pb(l);
        if(r - l + 1 > 1)
            len.insert({l, r - l + 1});
        l = r + 1;
    }
    reverse(all(start));
    int ans = 0;
    while(!start.empty())
    {
        int x = start.back();
        start.pop_back();
        if(len.empty())
        {
            // remove me and and the next
            ans++;
            if(!start.empty())
                start.pop_back();
        }
        else
        {
            pi best = *len.begin();
            len.erase(len.begin());
            if(best.ff == x)
            {
                // i am the best option
                // do both from me
                ans++;
            }
            else
            {
                // remove from best
                // remove me
                ans++;
                best.ss--;
                if(best.ss > 1)
                    len.insert(best);
            }
        }
    }

    cout << ans << endl;
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