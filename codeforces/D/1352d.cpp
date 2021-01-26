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
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    deque<int> arr(n);
    for(int i = 0, x; i < n; i++)
        cin >> x, arr.pb(x);
    ll ans[2] = {0}, prev[2] = {0};
    bool turn = 1;
    int games = 0;
    while(!arr.empty())
    {
        ll cur = 0;
        if(turn)
            while(!arr.empty() && cur <= prev[turn ^ 1])
                cur += arr.front(), arr.pop_front();
        else
            while(!arr.empty() && cur <= prev[turn ^ 1])
                cur += arr.back(), arr.pop_back();
        ans[turn] += cur;
        prev[turn] = cur;
        turn ^= 1;
        games++;
    }
    cout << games << " " << ans[1] << " " << ans[0] << endl;
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