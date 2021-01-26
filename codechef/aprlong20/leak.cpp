#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;
int cheat[505][5005];
void cp()
{
    int n, m, k, x;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &cheat[i][j]);
        }
    }
    int fre[n][m + 1];
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
           	fre[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            fre[i][cheat[i][j]]++;
        }
    }
    vector<int> res;
    for(int i = 0; i < n; i++)
    {
    	int mf = INT_MIN, f = -1;
        for(int j = 1; j <= m; j++)
        {
            if(fre[i][j] >= mf)
            	mf = fre[i][j], f = j;
        }
        res.pb(f);
    }
    for(int x: res)
    	printf("%d ", x);
    printf("\n");
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    scanf("%d", &t);
    while(t--)
    {
        cp();
    }
    return 0;
}