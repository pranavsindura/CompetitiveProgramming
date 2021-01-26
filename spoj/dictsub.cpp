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
const int MAXN = 1e4 + 5;

void cp()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> pos(26);
    for(int i = 0; i < ln(s); i++)
        pos[s[i] - 'A'].pb(i);

    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        bool ok = true;
        // convert RLE to actual string
        int num = 0, j = 0, p = 0;
        while(j < ln(t))
        {
            if(isdigit(t[j]))
                num = num * 10 + (t[j] - '0');
            else
            {
                // num times t[j]
                int c = t[j] - 'A';

                // adjust idx according to p
                int lo = 0, hi = sz(pos[c]) - 1;
                int idx = sz(pos[c]);
                while(lo <= hi)
                {
                    int mid = (lo + hi) >> 1;
                    if(pos[c][mid] >= p)
                        idx = mid, hi = mid - 1;
                    else
                        lo = mid + 1;
                }

                if(sz(pos[c]) - idx < num)
                    ok = false;
                else
                {
                    idx += num;
                    p = pos[c][idx - 1] + 1;
                }
                num = 0;
            }
            j++;
        }
        cout << (ok ? "YES\n" : "NO\n");
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
        cout << endl;
    }
    return 0;
}