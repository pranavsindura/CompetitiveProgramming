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
    int d;
    cin >> d;
    if(d == 0)
    {
        cout << "1\n1\n";
        return;
    }
    vector<int> arr;

    // reduce d to < 10^5
    // try adding 9*10^4
    int mul = d / 90000;
    d %=  90000;
    arr.pb(90001);
    for(int i = 0; i < mul; i++)
        arr.pb(90002);

    arr.pb(1);
    arr.pb(d + 1);
    arr.pb(d + 2);

    cout << sz(arr) << endl;
    for(int x : arr)
        cout << x << " ";
    cout << endl;
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