#include <bits/stdc++.h>
#define ll long long int
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
    int n;
    cin >> n;
    map<string, int> m;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        m[s]++;
    }
    int maxp = INT_MIN;
    for(auto x : m)
    {
        if(x.second > maxp)
        {
            maxp = x.second;
            s = x.first;
        }
    }
    cout<<s;
}