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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    
    vector<int> op(n, -1);
    vector<pi> query;
    int lim = 0;


    // Cleaning Queries
    for(int i = 0; i < m; i++)
    {
        int t, r;
        cin >> t >> r;
        if(!query.empty())
        {
            bool done = false;
            query.push_back({t, r});
            while(!done && sz(query) > 1)
            {
                done = true;
                pi place = query.back();
                query.pop_back();
                pi last = query.back();
                query.pop_back();

                if(last.ff == place.ff)
                    place.ss = max(last.ss, place.ss), done = false;
                else if(place.ss >= last.ss)
                    done = false;
                else
                    query.push_back(last);

                query.push_back(place);
            }
        }
        else
            query.push_back({t, r});
    }

    // Find last query for every prefix
    for(int i = 0; i < sz(query); i++)
    {
        int t = query[i].ff, r = query[i].ss;
        op[r - 1] = t;
        lim = max(lim, r - 1);
    }

    // Copy operation type from parent prefix
    for(int i = n - 2; i >= 0; i--)
        if(op[i] == -1)
            op[i] = op[i + 1];

    vector<int> ans(n);

    // Copy untouched indices
    for(int i = n - 1; i > lim; i--)
        if(op[i] == -1)
            ans[i] = arr[i], arr.pop_back();

    sort(all(arr));
    int l = 0, r = sz(arr) - 1;
    // Copy values based on operation type
    for(int i = lim; i >= 0; i--)
        ans[i] = op[i] == 1 ? arr[r--] : arr[l++];

    for(int x : ans)
        cout << x << " ";
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