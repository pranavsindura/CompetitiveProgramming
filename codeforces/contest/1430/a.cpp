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
const int MAXN = 1e3 + 5;

tuple<int, int, int> save[MAXN];
bool can[MAXN];

void init()
{
    for(int i = 0; i <= MAXN / 3 + 1; i++)
    {
        for(int j = 0; j <= MAXN / 5 + 1; j++)
        {
            for(int k = 0; k <= MAXN / 7 + 1; k++)
            {
                int val = i * 3 + j * 5 + k * 7;
                if(val <= 1000)
                {
                    can[val] = true;
                    save[val] = make_tuple(i, j, k);
                }
            }
        }
    }
}

void cp()
{
    int n;
    cin >> n;
    if(can[n])
        cout << get<0>(save[n]) << " " << get<1>(save[n]) << " " << get<2>(save[n]) << endl;
    else
        cout << -1 << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}