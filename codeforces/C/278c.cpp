#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 100 + 5;

bool vis[MAXN][MAXN], lang_learnt[MAXN][MAXN];
int n, m, cost;

void dfs(int u, int par)
{
    if(vis[par][u])
        return;
    vis[par][u] = true;
    for(int i = 1; i <= m; i++)
    {
        if(lang_learnt[u][i])
        {
            for(int j = 1; j <= n; j++)
            {
                if(lang_learnt[j][i])
                {
                    dfs(j, par);
                }
            }
        }
    }
}

void cp()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int s;
        int lang;
        cin >> s;
        for(int j = 0; j < s; j++)
        {
            cin >> lang;
            lang_learnt[i][lang] = true;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        dfs(i, i);
        for(int j = 1; j <= n; j++)
        {
            if(!vis[i][j])
            {
                bool any = false;
                for(int k = 1; k <= m; k++)
                {
                    if(!lang_learnt[i][k] && lang_learnt[j][k])
                    {
                        lang_learnt[i][k] = true;
                        cost++;
                        any = true;
                        break;
                    }
                }
                if(!any)
                {
                    // j has not learnt any language
                    // make j learn one of your langs, costs 1
                    for(int k = 1; k <= m; k++)
                    {
                        if(lang_learnt[i][k] && !lang_learnt[j][k])
                        {
                            lang_learnt[j][k] = true;
                            cost++;
                            any = true;
                            break;
                        }
                    }
                }

                if(!any)
                {
                    // i and j both have not learnt any language
                    // make i and j learn any of the langs, costs 2
                    for(int k = 1; k <= m; k++)
                    {
                        if(!lang_learnt[i][k] && !lang_learnt[j][k])
                        {
                            lang_learnt[i][k] = lang_learnt[j][k] = true;
                            cost++, cost++;
                            any = true;
                            break;
                        }
                    }
                }
                dfs(j, i);
            }
        }
    }
    cout << cost;
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