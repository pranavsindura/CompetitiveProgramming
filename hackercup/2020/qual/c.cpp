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
// len, number line pos
ll len[MAXN][3];
ll pos[MAXN][3];
pi arr[MAXN];
int p[MAXN], h[MAXN];
// 0->ignored
// 1->fell left
// 2->fell right
void cp()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].ff >> arr[i].ss;

    sort(arr + 1, arr + n + 1);
    // Translate to 0
    for(int i = 2; i <= n; i++)
        arr[i].ff -= arr[1].ff;
    arr[1].ff = 0;

    for(int i = 1; i <= n; i++)
        p[i] = arr[i].ff, h[i] = arr[i].ss;

    ll mx_len = 0;
    cout << mx_len << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}