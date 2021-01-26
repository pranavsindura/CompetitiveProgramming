#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    ll n;
    cin >> n;
    vector<int> f, l;
    vector<pii> x;
    ll count = 0;
    ll tot = n*n;
    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> arr(m);
        for(int j = 0; j < m; j++)
        {
            cin >> arr[j];
        }
        bool ascent = false;
        int mi = arr[0];
        for(int j = 0; j < sz(arr); j++)
        {
            mi = min(mi, arr[j]);
            if(arr[j] > mi)
            {
                ascent = true;;
                break;
            }
        }
        if(!ascent){
            f.push_back(arr[0]);
            l.push_back(arr[m-1]);
            x.push_back(make_pair(f.back(), l.back()));
            if(f.back() == l.back())
                tot++, count++;
        }
    }
    sort(all(f));
    sort(all(l));
    for(int i=0;i<sz(x);i++)
    {
        auto it = upper_bound(all(f), x[i].second);
        if(it == f.end())
        {
            count += sz(f);
        }
        else
        {
            int ind = it-f.begin();
            int total = ind;
            count+=total;
        }
        // if(x[i].second > x[i].first)
        //     count++;
        // auto it2 = upper_bound(all(l), x[i].first)
        // if(it2 == l.end())
        //     continue;
        // else
        // {
        //     int ind = it-l.begin();
        //     int total = sz(l) - ind;
        //     count+=total;
        // }
    }
    // for(int i=0;i<sz(l);i++)
    // {
    //     auto it = upper_bound(all(f), l[i]);
    //     if(it == f.end())
    //     {
    //         count += sz(f);
    //     }
    //     else
    //     {
    //         int ind = it-f.begin();
    //         int total = ind;
    //         count+=total;
    //     }
    // }
    ll ans = tot - count;
    cout<<ans;
    // cout<<tot<<" "<<count;
    return 0;
}