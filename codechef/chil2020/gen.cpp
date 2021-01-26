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
    int n = 1e5, q = 1e5;
    cout << n << " " << q << endl;
    for(int i = 0; i < n; i++)
        cout << rand() << " ";
    cout << endl;
    while(q--)
    {
        int l = rand() % n + 1;
        int r = rand() % n + 1;
        if(l > r)
            swap(l, r);
        cout << l << " " << r << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    srand(time(NULL));
    // cout << t << endl;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}