#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
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
const double PI = acos(-1.0);

void cp()
{
    int n;
    cin >> n;
    vector<pii> circle(n), range(n);
    vector<int> ans(n, -1), res(n, -1);
    map<pii, int> index_of;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        circle[i] = mp(a, b);
        range[i] = mp(a - b, a + b);
        index_of[range[i]] = i;
    }
    sort(all(range));
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        auto it = lower_bound(all(range), mp(x, x));
        if(it != end(range))
        {
            int ind = it - begin(range);
            if(x >= range[ind].ff && x <= range[ind].ss)
            {
                int rad = (range[ind].ss - range[ind].ff) / 2;
                int center = range[ind].ff + rad;
                if((x - center) * (x - center) + y * y <= rad * rad)
                {
                    //ok
                    if(ans[ind] == -1)
                        ans[ind] = i + 1;
                }
            }
            ind--;
            if(ind >= 0)
            {
                if(x >= range[ind].ff && x <= range[ind].ss)
                {
                    int rad = (range[ind].ss - range[ind].ff) / 2;
                    int center = range[ind].ff + rad;
                    if((x - center) * (x - center) + y * y <= rad * rad)
                    {
                        //ok
                        if(ans[ind] == -1)
                            ans[ind] = i + 1;
                    }
                }
            }
        }
        else
        {
            int ind = n - 1;
            if(x >= range[ind].ff && x <= range[ind].ss)
            {
                int rad = (range[ind].ss - range[ind].ff) / 2;
                int center = range[ind].ff + rad;
                if((x - center) * (x - center) + y * y <= rad * rad)
                {
                    //ok
                    if(ans[ind] == -1)
                        ans[ind] = i + 1;
                }
            }
        }
    }
    //reconstruct
    int found = 0;
    for(int i = 0; i < n; i++)
    {
        res[index_of[range[i]]] = ans[i];
        if(ans[i] != -1)
            found++;
    }
    cout << found << endl;
    for(int x : res)
        cout << x << " ";
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