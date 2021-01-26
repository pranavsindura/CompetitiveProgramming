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

void cp()
{
    int n, one = 0, zero = 0;
    cin >> n;
    vector<int> a(n), b(n), sorted;
    for(int &x : a)
    {
        cin >> x;
        sorted.pb(x);
    }
    for(int &x : b)
    {
        cin >> x;
        if(x)
            one++;
        else
            zero++;
    }
    sort(all(sorted));
    bool ok = true;
    if(a == sorted)
    {
        //ok
    }
    else if(one == n || zero == n)
    {
        //not ok
        ok = false;
    }
    cout << (ok ? "Yes\n" : "No\n");
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