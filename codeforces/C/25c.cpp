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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int arr[305][305];
void cp()
{
    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    cin >> k;
    while(k--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        arr[a][b] = arr[b][a] = min(arr[a][b], c);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                arr[i][j] = min({arr[i][j], arr[i][a] + arr[a][b] + arr[b][j], arr[i][b] + arr[b][a] + arr[a][j]});
        ll sum = 0;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                sum += arr[i][j];
        cout << sum << " ";
    }
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