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
    while(t--)
    {
        string s;
        cin >> s;
        vector<pair<int, int>> c(26, make_pair(-1, -1));
        for(int i = 0; i < s.length(); i++)
        {
            if(c[s[i] - 'a'].first == -1)
                c[s[i] - 'a'] = make_pair(i, i);
            c[s[i] - 'a'].second = i;
        }
        int m = c[0].second - c[0].first;
        int ans = 0;
        for(int i = 1; i < 26; i++)
        {
            if(c[i].second - c[i].first > m)
            {
                m = c[i].second - c[i].first;
                ans = i;
            }
        }
        cout << char(ans + 97) << " " << m << endl;
    }
    return 0;
}