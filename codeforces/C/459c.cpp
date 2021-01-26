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
int ans[1005][1005];
void cp()
{
    int n, k, d;
    cin >> n >> k >> d;
    int total = 1;
    bool ok = false;
    for(int i = 0; i < d; i++)
    {
        total *= k;
        if(total >= n)
        {
            ok = true;
            break;
        }
    }
    if(!ok)
    {
        cout << -1;
        return;
    }
    // d length number in base k
    int num[d];
    clr(num, 0);
    for(int i = 0; i < n; i++)
    {
        // for each ith person
        for(int j = 0; j < d; j++)
            ans[j][i] = num[j] + 1;
        // add 1 to number
        int carry = 1;
        for(int j = d - 1; j >= 0; j--)
        {
            int res = (num[j] + carry) % k;
            carry = (num[j] + carry) / k;
            num[j] = res;
        }
    }
    for(int i = 0; i < d; i++)
        for(int j = 0; j < n; j++)
            cout << ans[i][j] << " \n"[j == n - 1];
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