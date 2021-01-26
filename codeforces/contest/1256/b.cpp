#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        vector<int> arr(n), op(n+1);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int pos = 0;
        for(int i=0;i<n-1;i++)
        {
            vector<int>::iterator mine = min_element(arr.begin()+i, arr.end());
            int ind = mine - arr.begin();
            if(ind != pos)
            {
                for(int j=ind; j > pos; j--)
                {
                    if(op[j-1])
                        break;
                    else
                    {
                        swap(arr[j-1], arr[j]);
                        op[j-1] = 1;
                    }
                }
            }
            pos++;
        }
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}