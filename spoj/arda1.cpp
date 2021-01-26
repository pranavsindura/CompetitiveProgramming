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

char home[2005][2005];
char swamp[305][305];

void cp()
{
    int n1, n2, m1, m2;
    cin >> n1 >> n2;
    for(int i = 0; i < n1; i++)
        cin >> swamp[i];
    cin >> m1 >> m2;
    for(int i = 0; i < m1; i++)
        cin >> home[i];
    bool any = false;
    for(int i = 0; i <= m1 - n1; i++)
    {
        for(int j = 0; j <= m2 - n2; j++)
        {
            if(home[i][j] == swamp[0][0])
            {
                bool ok = true;
                for(int a = 0; a < n1 && ok; a++)
                {
                    for(int b = 0; b < n2 && ok; b++)
                    {
                        if(swamp[a][b] != home[i + a][j + b])
                            ok = false;
                    }
                }
                if(ok)
                    cout << "(" << i + 1 << "," << j + 1 << ")" << endl;
                any |= ok;
            }
        }
    }
    if(!any)
        cout << "NO MATCH FOUND...\n";
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