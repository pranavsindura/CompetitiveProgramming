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
const int MAXN = 1e5 + 5;
bool used[MAXN];
void cp()
{
    int n;
    cin >> n;
    if(n % 4 == 2 || n % 4 == 3)
    {
        cout << -1;
        return;
    }
    int x = 1;
    vector<int> ans(n + 1, -1);
    for(int i = 1; i <= n; i++)
    {
        if(ans[i] != -1)
            continue;
        int val = n - i + 1;
        if(i == val)
            ans[i] = i;
        else
        {
            int place = min(i, n - i + 1) + 1;
            int ind = i;
            while(ans[ind] == -1)
            {
                ans[ind] = place;
                place = n - ind + 1;
                ind = ans[ind];
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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