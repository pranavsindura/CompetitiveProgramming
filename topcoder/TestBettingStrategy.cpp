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
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int n, req;
double p;

double dp[2500][51][11];

double solve(int sum, int round, int place)
{
    if(round == n)
        return sum >= req;
    if(sum >= req)
        return 1;

    double &ret = dp[sum][round][place];
    if(fabs(ret + 1) > eps)
        return ret;

    double ans = 0;
    // we are going to place a bet of 2^place
    if(sum >= (1 << place))
        ans += p * solve(sum + (1 << place), round + 1, 0) + (1 - p) * solve(sum - (1 << place), round + 1, place + 1);
    return ret = ans;
}

class TestBettingStrategy
{
public:
    double winProbability(int initSum, int goalSum, int rounds, int prob)
    {
        n = rounds;
        p = double(prob) / 100.0;
        clr(dp, -1);
        req = goalSum;
        return solve(initSum, 0, 0);
    }
};

int main()
{
    TestBettingStrategy obj;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << obj.winProbability(a, b, c, d) << endl;
    return 0;
}