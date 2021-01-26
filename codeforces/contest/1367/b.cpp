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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> even_odd, odd_even;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(i % 2 == 0 && arr[i] % 2 == 1)
        {
            even_odd.pb(i);
        }
        else if(i % 2 == 1 && arr[i] % 2 == 0)
        {
            odd_even.pb(i);
        }
    }
    if(sz(odd_even) == sz(even_odd))
        cout << sz(odd_even) << endl;
    else
        cout << -1 << endl;
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