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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

double ncr[101][101];

void init()
{
    for(int i = 0; i <= 100; i++)
    {
        ncr[i][0] = 1;
    }
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
}
double fpow(double x, int y)
{
    double res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}
void cp()
{
    int m, w, c;
    while(cin >> m >> w >> c && (m || w))
    {
        double pm = (m * 1.0) / (m * 1.0 + w * 1.0);
        double pw = 1 - pm;
        double ans = 0;
        for(int i = 0; i <= c; i += 2)
        {
            ans += ncr[c][i] * fpow(pm, i) * fpow(pw, c - i);
        }
        cout << setprecision(7) << fixed << ans << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

/*


//  Idea:
//    - Dynamic Programming.
//    - dp[men][rem]:
//      `men` represents the number of the gentle men take candies till now.
//      `rem` represents the number of remaining candies.
//    - In each step calculate the probability of give the current candy
//      to a gentle men or to a woman and sum the probabilities.


#include <bits/stdc++.h>

using namespace std;

int m, w, c;
double dp[1000][100];

double rec(int men, int rem) {
  if(rem == 0)
    return men % 2 == 0;

  double &ret = dp[men][rem];
  if(ret == ret)
    return ret;
  ret = 0;

  return ret = 1.0 * m / (m + w) * rec(men + 1, rem - 1) + 1.0 * w / (m + w) * rec(men, rem - 1);
}

int main() {
  while(scanf("%d %d %d", &m, &w, &c) && (m != 0 || w != 0)) {
    memset(dp, -1, sizeof dp);
    printf("%0.7lf\n", rec(0, c));
  }

  return 0;
}
*/