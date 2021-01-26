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
const int MAXN = 1e6 + 5;

map<pi, bool> vis;
map<pi, bool> dp;

// ll rec(ll a, ll b)
// {
//     if(a == 0 || b == 0)
//         return 0;
//     else
//     {
//         if(a < b)
//             swap(a, b);
//         if(a / b > 1) // play largest even multiple to swap turns
//             return 1;
//         else
//             return rec(b, a - b) + 1;
//     }
// }

ll winner(bool p, ll a, ll b)
{
    if(b == 0)
        return !p;
    else
    {
        bool win = !p;
        if(a / b > 1 && (winner(!p, b + a % b, b) == p) )
            win = p;
        if(winner(!p, b, a % b) == p)
            win = p;
        return win;
    }
}

void cp()
{
    ll a, b;
    while(true)
    {
        cin >> a >> b;
        if(!a && !b)
            break;
        if(a < b)
            swap(a, b);
        bool stan = winner(true, a, b);
        if(stan)
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
        // ll turns = rec(a, b);
        // if(turns % 2)
        //     cout << "Stan wins\n";
        // else
        //     cout << "Ollie wins\n";
    }
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