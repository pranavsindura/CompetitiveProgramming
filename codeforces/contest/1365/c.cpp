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

void cp()
{
    int n;
    cin >> n;
    vector<int> pos_a(n + 1), pos_b(n + 1);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos_a[x] = i;
    }
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos_b[x] = i;
    }
    map<int, int> need;
    for(int i = 1; i <= n; i++)
    {
        if(pos_b[i] <= pos_a[i])
        {
            need[pos_a[i] - pos_b[i]]++;
        }
        else
        {
            int right_down = n - pos_b[i] - 1;
            int right_up = pos_a[i] + 1;
            need[right_down + right_up]++;
        }
    }
    int mx = 1;
    for(auto x : need)
    {
        // cout << x.ff << " " << x.ss << endl;
        mx = max(mx, x.ss);
    }
    cout << mx << endl;
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