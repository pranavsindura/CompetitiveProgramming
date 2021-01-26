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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
using namespace std;

struct logo
{
    int first, second;
    char comp;
    const bool operator<(const logo &e)const
    {
        return mp(first, second) < mp(e.first, e.second);
    };
};

void cp()
{
    vector<logo> arr(3);
    for(int i = 0; i < 3; i++)
        cin >> arr[i].ff >> arr[i].ss, arr[i].comp = 'A' + i;
    sort(all(arr));
    bool ok = false;
    vector<vector<char>> ans;
    do
    {
        for(int bit = 0; bit < 1 << 3 && !ok; bit++)
        {
            int a = arr[0].ff, b = arr[0].ss;
            int c = arr[1].ff, d = arr[1].ss;
            int e = arr[2].ff, f = arr[2].ss;
            if((bit >> 0) & 1)
                swap(a, b);
            if((bit >> 1) & 1)
                swap(c, d);
            if((bit >> 2) & 1)
                swap(e, f);

            if(b == d)
            {
                if(a + c == f && b + e == f)
                {
                    ok = true;
                    ans = vector<vector<char>>(f, vector<char>(f, 'X'));
                    for(int i = 0; i < b; i++)
                        for(int j = 0; j < a; j++)
                            ans[i][j] = arr[0].comp;
                    for(int i = 0; i < b; i++)
                        for(int j = a; j < f; j++)
                            ans[i][j] = arr[1].comp;
                    for(int i = b; i < f; i++)
                        for(int j = 0; j < f; j++)
                            ans[i][j] = arr[2].comp;
                }
                else if(e == b && a + c + f == b)
                {
                    ok = true;
                    ans = vector<vector<char>>(b, vector<char>(b, 'X'));
                    for(int i = 0; i < b; i++)
                        for(int j = 0; j < a; j++)
                            ans[i][j] = arr[0].comp;
                    for(int i = 0; i < b; i++)
                        for(int j = a; j < a + c; j++)
                            ans[i][j] = arr[1].comp;
                    for(int i = 0; i < b; i++)
                        for(int j = a + c; j < a + c + f; j++)
                            ans[i][j] = arr[2].comp;
                }
            }
        }
    }
    while(next_permutation(all(arr)) && !ok);
    
    if(ok)
    {
        cout << sz(ans) << endl;
        for(int i = 0; i < sz(ans); i++, cout << endl)
            for(int j = 0; j < sz(ans[i]); j++)
                cout << ans[i][j];
    }
    else
        cout << -1 << endl;
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