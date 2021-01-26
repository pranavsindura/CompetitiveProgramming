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
int sum(int l, int r, int arr[])
{
    int s = arr[r];
    if(l) s -= arr[l - 1];
    return s;
}
int main()
{
    FASTIO;
    string a, b;
    cin >> a >> b;
    int pre[ln(b)];
    pre[0] = (b[0] == '1');
    for(int i = 1; i < ln(b); i++)
    {
        pre[i] = pre[i - 1] + (b[i] == '1');
    }
    ll ans = 0;
    for(int j = 0; j < ln(a); j++)
    {
        int one = sum(j, ln(b) - ln(a) + j, pre);
        int zero = ln(b) - ln(a) + 1 - one;
        int diff = (a[j] == '1');
        ans += abs(1 - diff) * one + abs(0 - diff) * zero;
    }
    cout << ans;
    return 0;
}