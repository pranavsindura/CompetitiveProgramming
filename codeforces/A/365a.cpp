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
    int n, k, c = 0;
    string s;
    set<char> cs;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cs.clear();
        cin >> s;
        for(int j = 0; j < s.length(); j++)
        {
            cs.insert(s[j]);
        }
        bool f = true;
        for(int j = 0; j <= k; j++)
        {
            if(!cs.count('0' + j))
            {
                f = false;
                break;
            }
        }
        if(f)
            c++;
    }
    cout << c;
    return 0;
}