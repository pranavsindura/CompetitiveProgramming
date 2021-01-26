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
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    int n, m;
    ll total = 0;
    cin >> n >> m;
    vector<int> op(m);
    for(int &x : op)
        cin >> x, total += x;
    if(total < 1LL*n)
    {
        cout << -1;
        return;
    }

    int pos = n;
    vector<int> ans;
    bool ok = true;
    int left_most = n;
    for(int i = 0; i < m; i++)
    {
        if(op[i] > pos)
        {
            ok = false;
            break;
        }
        else
        {
            ans.pb(pos - op[i] + 1);
            left_most = min(ans.back(), left_most);
            pos--;
        }
    }
    if(!ok)
    {
        cout << -1;
        return;
    }
    //increase distance
    if(pos > 0) // more numbers can come, might have empty spaces
    {
        left_most = 1;
        for(int i = sz(ans) - 1; i >= 0; i--)
        {
            if(ans[i] > left_most)
            {
                //there is empty space
                // move ans[i] to left most
                ans[i] = left_most;
                left_most += op[i];
            }
            else
                break;
        }
    }
    for(int x : ans)
        cout << x << " ";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}