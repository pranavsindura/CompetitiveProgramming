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

void cp()
{
    int n;
    cin >> n;
    vector<int> idx(n);
    iota(all(idx), 1);
    vector<bool> picked(n + 1);
    vector<int> arr(n);

    while(sz(idx) > 1)
    {
        int i = idx.back();
        idx.pop_back();
        int j = idx.back();
        idx.pop_back();
        if(i > j)
            swap(i, j);

        cout << "? " << i << " " << j << endl;
        cout.flush();
        int x;
        cin >> x;
        cout << "? " << j << " " << i << endl;
        cout.flush();
        int y;
        cin >> y;

        if(x > y)
        {
            arr[i - 1] = x;
            picked[x] = 1;
            idx.pb(j);
        }
        else
        {
            arr[j - 1] = y;
            picked[y] = 1;
            idx.pb(i);
        }
    }
    int left = -1;
    for(int i = 1; i <= n; i++)
        if(!picked[i])
            left = i;
    if(left != -1)
    {
        for(int i = 0; i < n; i++)
            if(!arr[i])
                arr[i] = left;
    }
    cout << "! ";
    for(int x : arr)
        cout << x << " ";
    cout << endl;
    cout.flush();
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