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
int n;
double prob[105], dp[105], mul[105];

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> prob[i];
    sort(prob, prob + n);
    reverse(prob, prob + n);
    cout << setprecision(10) << fixed;
    for(int i = 0; i < n; i++)
    {
        dp[i] = prob[i];
        mul[i] = 1 - prob[i];
        for(int j = 0; j < i; j++)
        {
            if(dp[j] * (1 - prob[i]) + mul[j] * prob[i] > dp[i])
                dp[i] = dp[j] * (1 - prob[i]) + mul[j] * prob[i], mul[i] = mul[j] * (1 - prob[i]);
        }
    }
    double ans = *max_element(dp, dp + n);
    cout << ans << endl;
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