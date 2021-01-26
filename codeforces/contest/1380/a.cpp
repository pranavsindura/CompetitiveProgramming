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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr;
    int pos[n + 1];
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.pb(x);
        pos[x] = i;
    }
    int l = INT_MAX, r = INT_MIN;
    for(int i = 1; i <= 2; i++)
        l = min(l, pos[i]), r = max(r, pos[i]);
    for(int i = 3; i <= n; i++)
    {
        if(l < pos[i] && r > pos[i])
        {
            cout << "YES\n";
            cout << l + 1 << " " << pos[i] + 1 << " " << r + 1 << endl;
            return;
        }
        l = min(l, pos[i]);
        r = max(r, pos[i]);
    }
    cout << "NO\n";
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