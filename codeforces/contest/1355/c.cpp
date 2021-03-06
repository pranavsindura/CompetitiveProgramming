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
const int MAXN = 1e6 + 5;
ll diff[MAXN];
ll arr[MAXN];
void cp()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for(int i = a; i <= b; i++)
        diff[i + b]++, diff[i + c + 1]--;

    arr[0] = diff[0];
    for(int i = 1; i < MAXN; i++)
        arr[i] = diff[i] + arr[i - 1];

    clr(diff, 0);
    for(int i = 1; i < MAXN; i++)
        diff[0] += arr[i], diff[i] -= arr[i];

    clr(arr, 0);
    arr[0] = diff[0];
    for(int i = 1; i < MAXN; i++)
        arr[i] = diff[i] + arr[i - 1];

    for(int i = 1; i < MAXN; i++)
        arr[i] += arr[i - 1];
    
    cout << arr[d] - arr[c - 1] << endl;
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