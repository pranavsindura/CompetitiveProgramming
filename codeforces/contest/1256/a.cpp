#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int a,b,n,S;
        cin>>a>>b>>n>>S;
        int div = S/n;
        int rem = S%n;
        if(div <= a && rem <= b)
        {
            cout<<"YES\n";
        }
        else if(div >a && rem > b)
        {
            cout<<"NO\n";
        }
        else if(div > a && rem <= b)
        {
            int ext = S - (a*n);
            if(ext <= b)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            int ext = S - b;
            if(ext%n)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
    return 0;
}