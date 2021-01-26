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

int main()
{
    FASTIO;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> st(k), en(k);
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        st[i] = mp(a, b);
    }
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        en[i] = mp(a, b);
    }
    string ans;
    //collect all chips to 1,1 by doing n-1 U and m-1 L then visit all squares
    for(int i = 0; i < n - 1; i++)
        ans += "U";
    for(int i = 0; i < m-1; i++)
        ans += "L";
    bool f = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            if(f)
            {
                ans += "R";
            }
            else
            {
                ans += "L";
            }
        }
        ans += "D";
        f = !f;
    }
    cout << sz(ans) << endl << ans;
    return 0;
}