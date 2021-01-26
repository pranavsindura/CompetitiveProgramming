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



void cp()
{
    ll l, r, m, a, b, c;
    cin >> l >> r >> m;
    ll mn = l - r, mx = r - l;

    auto check = [&](ll a, ll b, ll c){return (b >= l && b <= r && c >= l && c <= r && (m + c - b) / a > 0);};

    auto solve = [&](ll l, ll r)
    {
        for(ll a = l; a <= r; a++)
        {
            ll rem = m % a, x = -rem, y = a - rem;
            if     (x >= mn && x <= mx && check(a, l - x, l))return make_tuple(a, l - x, l);
            else if(x >= mn && x <= mx && check(a, l, l + x))return make_tuple(a, l, l + x);
            else if(y >= mn && y <= mx && check(a, l - y, l))return make_tuple(a, l - y, l);
            else if(y >= mn && y <= mx && check(a, l, l + y))return make_tuple(a, l, l + y);
        }
    };
    tie(a, b, c) = solve(l, r);
    cout << a << " " << b << " " << c << endl;
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

// // m = n*a + b - c
// for(ll a = l; a <= r; a++)
// {
//     // m - (b-c) mod a == 0
//     // m + offset mod a == 0
//     ll rem = m % a;
//     // either remove rem or add m-rem
//     ll x = -rem, y = a - rem;

//     if(x >= mn && x <= mx)
//     {
//         // we have to make x = offset = -(b-c) = c - b

//         // assume c = l
//         ll c = l, b = l - x;
//         ll n = (m + x) / a;
//         if(b >= l && b <= r && c >= l && c <= r && n > 0)
//         {
//             cout << a << " " << b << " " << c << endl;
//             return;
//         }

//         // assume b = l
//         b = l, c = l + x;
//         if(b >= l && b <= r && c >= l && c <= r && n > 0)
//         {
//             cout << a << " " << b << " " << c << endl;
//             return;
//         }
//     }
//     if(y >= mn && y <= mx)
//     {
//         // we have to make y = c - b

//         // assume c = l
//         ll c = l, b = l - y;
//         ll n = (m + y) / a;
//         if(b >= l && b <= r && c >= l && c <= r && n > 0)
//         {
//             cout << a << " " << b << " " << c << endl;
//             return;
//         }

//         // assume b = l
//         b = l, c = l + y;
//         if(b >= l && b <= r && c >= l && c <= r && n > 0)
//         {
//             cout << a << " " << b << " " << c << endl;
//             return;
//         }
//     }
// }