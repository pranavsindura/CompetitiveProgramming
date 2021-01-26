#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

bool check(pi a, pi b)
{
    return !((a.ff < b.ff && a.ss < b.ff) || (b.ff < a.ff && b.ss < a.ff));
}

pi intersect(pi a, pi b)
{
    return {max(a.ff, b.ff), min(a.ss, b.ss)};
}

int get_len(pi a)
{
    return a.ss - a.ff + 1;
}

void cp()
{
    int n;
    while(cin >> n && n)
    {
        pi X = {INT_MIN, INT_MAX}, Y = {INT_MIN, INT_MAX}, Z = {INT_MIN, INT_MAX};
        bool zero = false;
        for(int i = 0; i < n; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            pi currX = {a, a + d - 1};
            pi currY = {b, b + d - 1};
            pi currZ = {c, c + d - 1};
            if(check(X, currX) && check(Y, currY) && check(Z, currZ))
            {
                X = intersect(X, currX);
                Y = intersect(Y, currY);
                Z = intersect(Z, currZ);
            }
            else
                zero = true;
        }
        if(zero)
            cout << 0 << endl;
        else
        {
            int lenX = get_len(X);
            int lenY = get_len(Y);
            int lenZ = get_len(Z);
            cout << lenX * lenY * lenZ << endl;
        }
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