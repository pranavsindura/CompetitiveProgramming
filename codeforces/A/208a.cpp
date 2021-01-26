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
    string s;
    cin >> s;
    string wub = "WUB", find = "";
    int pos = 0;
    for(int i = 0; i < s.length(); i++)
    {
        bool f = true;
        for(pos = 0; pos < wub.length() && (i + pos < s.length()); pos++)
        {
            if(s[i + pos] != wub[pos])
                f = false;
        }
        if(pos == wub.length() && f)
        {
            find += " ";
            i += 2;
        }
        else
        {
            find += s[i];
        }
    }
    // cout<<find<<endl;
    string ans="";
    bool prevsp = true;
    for(char x : find)
    {
        if(x == ' ')
        {
            if(!prevsp)
            {
                ans+=" ";
                prevsp = true;
            }
            
        }
        else
        {
            ans += x;
            prevsp = false;
        }
    }
    cout<<ans;
    return 0;
}