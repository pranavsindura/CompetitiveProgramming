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
int arr[MAXN];
int t[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return INT_MAX;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        return min(
                   query(v << 1, tl, tm, l, min(r, tm)),
                   query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r)
               );
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while(q--)
    {
        string s;
        cin >> s;
        string op = s.substr(0, 5);

        for(char &x : s)
            if(x > '9' || x < '0')
                x = ' ';

        vector<int> nums;
        stringstream ss(s);
        int x;
        while(ss >> x)
            nums.pb(x - 1);

        if(op == "query")
            cout << query(1, 0, n - 1, nums[0], nums[1]) << endl;
        else
        {
            // swap and update
            int temp = arr[nums[0]];
            for(int i = 0; i < sz(nums) - 1; i++)
            {
                // put arr[nums[i+1]] into arr[nums[i]]
                arr[nums[i]] = arr[nums[i + 1]];
                update(1, 0, n - 1, nums[i], arr[nums[i + 1]]);
            }
            arr[nums.back()] = temp;
            update(1, 0, n - 1, nums.back(), temp);
        }
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