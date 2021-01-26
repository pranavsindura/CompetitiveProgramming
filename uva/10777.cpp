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

int dcmp(ld a, ld b)
{
    return  (fabsl(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

void cp()
{
    int n;
    cin >> n;
    ld avg_len = 0, prob_away = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        ld p;
        cin >> x >> p;
        if(x < 0)
            prob_away += p;
        avg_len += abs(x * 1.0) * p;
    }
    // if prob_away < 1, then we can get it as a expected value of random variable avg_len * 1/(1 - prob_away)
    // else answer is not possible
    if(dcmp(prob_away, 1.0) == 0)
        cout << "God! Save me";
    else
    {
        ld ans = avg_len / (1.0 - prob_away);
        cout << setprecision(2) << fixed << ans;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int test = 1; test <= t; test++)
    {
        cout << "Case " << test << ": ";
        cp();
        cout << endl;
    }
    return 0;
}