#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

char arr[2005][2005];

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans(10);
    vector<vector<vector<int>>> row(10, vector<vector<int>>(n));
    vector<vector<vector<int>>> col(10, vector<vector<int>>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            row[arr[i][j] - '0'][i].pb(j);
    for(int j = 0; j < n; j++)
        for(int i = 0; i < n; i++)
            col[arr[i][j] - '0'][j].pb(i);

    for(char d = '0'; d <= '9'; d++)
    {
        for(int i = 0; i < n; i++)
        {
            int x = n, y = -1;
            if(!row[d - '0'][i].empty())
                x = row[d - '0'][i].front();
            if(!row[d - '0'][i].empty())
                y = row[d - '0'][i].back();
            x++, y++;
            for(int j = 0; j < n; j++)
            {
                if(!row[d - '0'][j].empty())
                {
                    // change x
                    int val = (y - 1) * abs(i - j);
                    ans[d - '0'] = max(ans[d - '0'], val);
                    // change y
                    val = (n - x) * abs(i - j);
                    ans[d - '0'] = max(ans[d - '0'], val);
                }
                // change j
                int val = (y - x) * abs(i - j);
                ans[d - '0'] = max(ans[d - '0'], val);
            }
        }
        for(int j = 0; j < n; j++)
        {
            int x = n, y = -1;
            if(!col[d - '0'][j].empty())
                x = col[d - '0'][j].front();
            if(!col[d - '0'][j].empty())
                y = col[d - '0'][j].back();
            x++, y++;
            for(int i = 0; i < n; i++)
            {
                if(!col[d - '0'][i].empty())
                {
                    // change x
                    int val = (y - 1) * abs(i - j);
                    ans[d - '0'] = max(ans[d - '0'], val);
                    // change y
                    val = (n - x) * abs(i - j);
                    ans[d - '0'] = max(ans[d - '0'], val);
                }
                // change j
                int val = (y - x) * abs(i - j);
                ans[d - '0'] = max(ans[d - '0'], val);
            }
        }
    }

    for(int x : ans)
        cout << x << " ";
    cout << endl;
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

