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
int n, m;
ll arr[15];
int guess[15];

set<ll> temp1, temp2, ans;

void rec(ll b, int picked, int i, ll num)
{
    if(b < 0)
    {
        if(picked == guess[i])
            temp1.insert(num);
    }
    else
    {
        // pick this bit
        if(picked < guess[i])
            rec(b - 1, picked + 1, i, num | (((arr[i] >> b) & 1LL) << b));
        // dont pick this bit, must be incorrect
        rec(b - 1, picked, i, num | ((~(arr[i] >> b) & 1LL) << b));
    }
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        bitset<35> x;
        cin >> x >> guess[i];
        arr[i] = x.to_ullong();
    }
    n--;
    rec(n, 0, 0, 0);
    ans = temp1;
    for(int i = 1; i < m; i++)
    {
        temp1.clear();

        rec(n, 0, i, 0);

        temp2.clear();
        for(ll x : ans)
            if(temp1.find(x) != temp1.end())
                temp2.insert(x);

        ans = temp2;
    }
    cout << sz(ans) << endl;
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