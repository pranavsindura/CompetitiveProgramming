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
    int z, oz, o;
    cin >> z >> oz >> o;
    string s;

    if(z > 0)
    {
        s += string(z + 1, '0');
        if(oz > 0)
        {
            if(oz % 2 == 0)
                s[0] = '1', s += '0', oz--;

            bool place = 1;
            while(oz--)
                s += char(48 + place), place ^= 1;
        }

        if(o > 0)
        {
            if(s.back() == '1')
                o--;
            s += string(o + 1, '1');
        }
    }
    else
    {
        if(o > 0)
            s += string(o + 1, '1');
        if(oz > 0)
        {
            if(s.empty())
                oz++;
            bool place = 0;
            while(oz--)
                s += char(48 + place), place ^= 1;
        }
    }

    cout << s << endl;
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