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
const int MAXN = 52;

int n, m;
int arr[MAXN];

ll C[MAXN][MAXN];
ld prob[MAXN][MAXN];
void init()
{
    clr(C, 0);
    for(int i = 0; i < MAXN; i++)
        C[i][0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
        {
            prob[i][j] = C[i][j];
            for(int k = 0; k < j; k++)
                prob[i][j] /= m;
        }
}

ld dp[MAXN][MAXN][MAXN];

ld solve(int i, int people, int mx)
{
    if(i == m)
        return (people ? 0 : mx);

    ld &ret = dp[i][people][mx];
    if(fabs(ret+1)>eps)
    	return ret;

    ld ans = 0;
    for(int j = 0; j <= people; j++)
        ans += prob[people][j] * solve(i + 1, people - j, max(mx, (j + arr[i] - 1) / arr[i]));
    return ret = ans;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> arr[i];
    fix(15);
    init();
    clr(dp, -1);
    cout << solve(0, n, 0) << endl;
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