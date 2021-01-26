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
    while(cin >> n)
    {
        int k = n * n;
        vector<pii> div;
        for(int i = 1; i <= sqrt(k); i++)
        {
            if(k % i == 0)
            {
                if(i == k / i)
                    div.pb({i, k / i});
                else if(i > k / i)
                    div.pb({i, k / i});
                else
                    div.pb({k / i, i});
            }
        }
        sort(allr(div));
        cout << sz(div) << endl;
        for(pii x : div)
        {
            cout << "1/" << n << " = " << "1/" << n + x.ff << " + " << "1/" << n + x.ss << endl;
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