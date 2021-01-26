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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

void cp()
{
    ll n;
    cin >> n;
    int count = 0;
    // if(n == 2)
    // {
    //     cout << 1;
    //     return;
    // }
    ll a = 0, b = 1;
    ll fib[90];
    fib[0] = 1;
    fib[1] = 2;
    for(int i = 2; i < 90; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    for(count = 1; count < 90 && fib[count] <= n; count++);
    cout << count - 1;
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