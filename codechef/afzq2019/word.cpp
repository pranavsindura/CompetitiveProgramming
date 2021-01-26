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
    int t;
    cin >> t;
    while (t--)
    {
        string r, g;
        cin>>r>>g;
        int pos = 0;
        for(int i=0;i<r.length() && pos<g.length();i++)
        {
            if(r[i] == g[pos])
                pos++;
        }
        if(pos == g.length())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}