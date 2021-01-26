#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    int rec=0, c=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
        {
            if(rec)
                rec--;
            else
                c++;
        }
        else
        {
            rec += arr[i];
        }
    }
    cout<<c;
    return 0;
}