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
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n, k;
    cin >> n;
    int c[n], p[n];
    for(int i = 0; i < n; i++)
        cin >> c[i] >> p[i];
    cin >> k;
    vector<pii> r(k);
    for(int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        r[i] = mp(a, i);
    }
    vector<bool> done(n, false);
    vector<int> ans(k, -1);
    sort(all(r));
    int count = 0, total = 0;
    for(int i = 0; i < k; i++)
    {
        int mx = INT_MIN;
        int ind = -1;
        for(int j = 0; j < n; j++)
        {
            if(!done[j] && c[j] <= r[i].first && p[j] > mx)
            {
                ind = j;
                mx = p[j];
            }
        }

        if(ind != -1)
        {
            ans[i] = ind;
            count++;
            total += p[ind];
            done[ind] = true;
        }
    }
    cout << count << " " << total << endl;
    for(int i = 0; i < k; i++)
    {
        //cout<<ans[i]<<endl;
        if(ans[i] == -1)continue;
        cout << ans[i] + 1 << " " << r[i].second + 1 << endl;
    }
    return 0;
}