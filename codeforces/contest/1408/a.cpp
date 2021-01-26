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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;
    for(int &x : c)
        cin >> x;
    vector<int> ans(n);
    ans[0] = a[0];
    for(int i = 1; i < n - 1; i++)
    {
        if(a[i] != ans[i - 1])
            ans[i] = a[i];
        else if(b[i] != ans[i - 1])
            ans[i] = b[i];
        else
            ans[i] = c[i];
    }
    if(a[n - 1] != ans[n - 2] && a[n - 1] != ans[0])
        ans[n - 1] = a[n - 1];
    else if(b[n - 1] != ans[n - 2] && b[n - 1] != ans[0])
        ans[n - 1] = b[n - 1];
    else
        ans[n - 1] = c[n - 1];
    for(int x : ans)
        cout << x << " ";
    cout << endl;
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