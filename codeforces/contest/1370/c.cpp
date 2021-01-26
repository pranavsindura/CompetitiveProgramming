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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

bool is_prime(int n)
{
    if(n % 2 == 0)
        return false;
    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

void cp()
{
    int n;
    cin >> n;
    bool a = false;
    if(n == 1)
        a = false;
    else if(n == 2)
        a = true;
    else if(n & 1)
        a = true;
    else
    {
        if(!is_prime(n / 2) && (n & (n - 1)))
            a = true;
    }
    cout << (a ? "Ashishgup\n" : "FastestFinger\n");
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