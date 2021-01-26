#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin>>n;
    string arr[] = {"I hate ","I love "};
    for(i=0;i<n;i++)
    {
        if(i%2 == 0)
            cout<<arr[0];
        else    
            cout<<arr[1];
        
        if(i==n-1)
            cout<<"it ";
        else
            cout<<"that ";
    }
    return 0;
}