
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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

ll fxor(ll n)
{
    ll r = n % 4;
    if(r == 0)
        return n;
    else if(r == 1)
        return 1;
    else if(r == 2)
        return n + 1;
    else
        return 0;
}

struct node{
    ll key;
    int ind;
    node *left, *right;
} *root = NULL;
#define node struct node

int main()
{
    FASTIO;
    ll n, q;
    cin >> n >> q;
    set<ll> lq;
    vector<ll> v;
    map<ll,int> ma;
    while(q--)
    {
        int t, ind;
        cin >> t >> ind;
        if(t == 1)
        {
            // lq.insert(ind);
            v.pb(ind);
            sort(all(v));
            ma[ind]++;
        }
        else
        {
            // vector<ll> v(all(lq));
            ll l = ind, r = n;
            ll lo = 0, hi = sz(v)-1;
            while(lo <= hi)
            {
                ll mid = (lo+hi)/2;
                if(v[mid] == l)
                {
                    l++;
                    hi = sz(v) - 1;
                }
                else if(v[mid] > l)
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            auto it = upper_bound(all(v), l);
            if(it != v.end())
                r = *it-1;
            // cout << l << " " << r << endl;

            // cout << l << " " << r << endl;
            ll ans = fxor(r) ^ fxor(l - 1);

            cout << ans << endl;
        }
        // cout << "SET:\n";
        // for(auto it = s.begin(); it != s.end(); it++)
        // {
        //     cout << it->first << ", " << it->second << endl;
        // }
    }
    return 0;
}
