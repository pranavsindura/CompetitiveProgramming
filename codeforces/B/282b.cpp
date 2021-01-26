#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<int> a(n), g(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> g[i];
    }
    string s;
    int ca = 0, cg = 0;
    for(int i = 0; i < n; i++)
    {
        if(abs(ca + a[i] - cg) <= abs(ca - cg - g[i]))
        {
            ca += a[i];
            s += "A";
        }
        else
        {
            cg += g[i];
            s += "G";
        }
    }
    if(abs(ca - cg) > 500)
        cout << "-1";
    else
    {
        cout << s;
    }
    return 0;
}
