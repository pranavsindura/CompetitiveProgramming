#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;

int main()
{
    FASTIO;
    vector<pair<int, int>> v = {{0, 100}, {2, 3}};
    sort(all(v));
    auto x = lower_bound(all(v), make_pair(1,1));
    if(x == v.end())
        cout<<-1;
    else
        cout<<x->first<<" "<<x->second<<endl;
    return 0;
}