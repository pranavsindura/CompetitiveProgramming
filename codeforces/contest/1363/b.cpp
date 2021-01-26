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

int sum(int l, int r, int pre[])
{
    if(l > r)
        return 0;
    return (l ? pre[r] - pre[l - 1] : pre[r]);
}

void cp()
{
    string s;
    cin >> s;
    int n = ln(s);
    int pre_one[n], pre_zero[n];
    if(n <= 2)
    {
        cout << 0 << endl;
        return;
    }
    pre_one[0] = s[0] == '1';
    pre_zero[0] = s[0] == '0';
    for(int i = 1; i < n; i++)
        pre_one[i] = pre_one[i - 1] + (s[i] == '1'), pre_zero[i] = pre_zero[i - 1] + (s[i] == '0');
    int cost = min(pre_zero[n - 1], pre_one[n - 1]);
    for(int i = 0; i < n; i++)
    {
        // make 0, before all zero and after all one
        int here = sum(0, i, pre_one) + sum(i + 1, n - 1, pre_zero);
        cost = min(cost, here);
        // make 1,  before all one and after all zero
        here = sum(0, i, pre_zero) + sum(i + 1, n - 1, pre_one);
        cost = min(cost, here);

    }
    cout << cost << endl;
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