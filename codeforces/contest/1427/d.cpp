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

void perform(vector<int> &arr, vector<int> &op)
{
    vector<vector<int>> group;
    while(!op.empty())
    {
        int last = op.back();
        op.pop_back();
        vector<int> temp;
        while(last--)
            temp.pb(arr.back()), arr.pop_back();
        reverse(all(temp));
        group.pb(temp);
    }
    for(auto &v : group)
        for(int x : v)
            arr.pb(x);
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    // n odd need to start putting at end
    // n even need to start putting at front

    // [1 3] [4 2] [5] [6]
    vector<vector<int>> ans;

    bool last = n & 1;
    for(int num = n; num >= 1; num--)
    {
        int solved = n - num;

        int pos = -1;
        for(int i = 0; i < n; i++)
            if(arr[i] == num)
                pos = i;

        vector<int> res;
        if(last)
        {
            // solved times 1
            // pos-solved+1
            // n-pos-1 if nonzero
            for(int i = 0; i < solved; i++)
                res.pb(1);
            res.pb(pos - solved + 1);
            if(n - pos - 1)
                res.pb(n - pos - 1);
        }
        else
        {
            // pos if nonzero
            // n-pos-solved
            // solved times 1
            if(pos)
                res.pb(pos);
            res.pb(n - pos - solved);
            for(int i = 0; i < solved; i++)
                res.pb(1);
        }
        if(sz(res) > 1)
            ans.pb(res), perform(arr, res);
        last ^= 1;
    }

    cout << sz(ans) << endl;
    for(auto v : ans)
    {
        cout << sz(v) << " ";
        for(int x : v)
            cout << x << " ";
        cout << endl;
    }
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