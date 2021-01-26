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
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<pi> group;
    int l = 0, r = 0;
    while(l < n)
    {
        while(l < n && s[l] == 'L')
            l++;
        if(l >= n)
            break;
        r = l;
        while(r + 1 < n && s[r + 1] == 'W')
            r++;
        group.pb({l, r});
        l = r + 1;
    }

    vector<pi> diff;
    for(int i = 0; i < sz(group) - 1; i++)
    {
        int d = group[i + 1].ff - group[i].ss - 1;
        diff.pb({d, i});
    }

    sort(allr(diff));
    while(k > 0 && !diff.empty())
    {
        pi last = diff.back();
        diff.pop_back();
        int can = min(last.ff, k);
        k -= can;
        for(int i = group[last.ss].ss + 1; i < group[last.ss + 1].ff && can > 0; i++, can--)
            s[i] = 'W';
    }

    // Now try after last W
    if(k > 0)
    {
        int pos = -2;
        for(int i = 0; i < n; i++)
            if(s[i] == 'W')
                pos = i;
        pos++;
        if(pos >= 0 && pos < n)
            for(int i = pos; i < n && k > 0; i++)
                if(s[i] == 'L')
                    s[i] = 'W', k--;
    }

    // Now try from first
    if(k > 0 && s[0] == 'L')
    {
        int pos = n;
        for(int i = 0; i < n && pos == n; i++)
            if(s[i] == 'W')
                pos = i;
        pos--;
        if(pos >= 0)
        {
            for(int i = pos; i >= 0 && k > 0; i--)
                if(s[i] == 'L')
                    s[i] = 'W', k--;
        }
    }

    int score = 0;
    for(int i = 0; i < n; i++)
    {
        score += (s[i] == 'W');
        if(i - 1 >= 0 && s[i] == 'W' && s[i - 1] == 'W')
            score++;
    }

    cout << score << endl;
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