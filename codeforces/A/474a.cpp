#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string lookup ="qwertyuiopasdfghjkl;zxcvbnm,./";
    char x;
    string s, ans;
    cin >> x >> s;
    if(x == 'R')
    {
        for(char e: s)
        {
            if(e == 'q' || e== 'a' || e == 'z')
                ans += e;
            else
            {
                for(int i=0;i<lookup.length();i++)
                {
                    if(lookup[i] == e)
                        ans+=lookup[i-1];
                }
            }
        }
    }
    else
    {
        for(char e: s)
        {
            if(e == 'p' || e== ';' || e == '/')
                ans += e;
            else
            {
                for(int i=0;i<lookup.length();i++)
                {
                    if(lookup[i] == e)
                        ans+=lookup[i+1];
                }
            }
        }
    }
    cout<<ans;
    return 0;
}