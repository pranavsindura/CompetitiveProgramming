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

int sum(int l, int r, int pre[])
{
    if(r < 0)
        return 0;
    l = max(l, 0);
    return (l ? pre[r] - pre[l - 1] : pre[r]);
}

void cp()
{
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    bool did_i[n + 1];
    clr(did_i, false);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'o')
        {
            did_i[i] = true;
            i += c;
            count++;
        }

    }
    if(count != k)
        return;
    vector<int> days;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == 'o')
        {

            if(did_i[i])
            {
                days.pb(i + 1);
            }
            i -= c;
        }
    }
    for(int i = sz(days) - 1; i >= 0; i--)
    {
        cout << days[i] << endl;
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