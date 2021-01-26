#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c=0, n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i+=2)
    {
        if(s[i] == 'a' && s[i+1] == 'a')
        {
            s[i+1] = 'b';
            c++;
        }
        else if(s[i] == 'b' && s[i+1] == 'b')
        {
            s[i+1] = 'a';
            c++;
        }
    }
    cout<<c<<endl<<s<<endl;
    return 0;
}
