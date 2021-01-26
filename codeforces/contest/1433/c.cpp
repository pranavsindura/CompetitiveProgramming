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
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    bool all = true;
    for(int i = 0; i < n - 1; i++)
        if(arr[i] != arr[i + 1])
            all = false;
    if(all)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        int mx = *max_element(all(arr));
        int pos = -1;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == mx)
            {
                if(i - 1 >= 0 && arr[i - 1] != mx)
                    pos = i;
                if(i + 1 < n && arr[i + 1] != mx)
                    pos = i;
            }
        }
        cout << pos + 1 << endl;
    }
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