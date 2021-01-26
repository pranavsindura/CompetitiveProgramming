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
    int n = 1e6;
    int k = 2;
    int w = 20;
    cout << n << " " << k << " " << w << endl;
    cout << rand() + 1 << " " << rand() + 1 << endl;
    cout << "1000000000 1000000000 1000000000 1000000000\n";
    cout << rand() + 1 << " " << rand() + 1 << endl;
    cout << "1000000000 1000000000 1000000000 1000000000\n";

}

int main()
{
    FASTIO;
    int t;
    t = 10;
    cout << t << endl;
    srand(time(NULL));
    while(t--)
    {
        cp();
    }
    return 0;
}