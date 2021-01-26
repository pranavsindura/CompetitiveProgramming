#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0,a=0;
    string s;
    cin>>n>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'D')
            d++;
        else
            a++;
    }
    if(a>d)
        cout<<"Anton";
    else if(a<d)
        cout<<"Danik";
    else
        cout<<"Friendship";
    return 0;
}