#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
int main()
{
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>s;
        bool one = false;
        int left, right, m = INT_MIN;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '1')
            {
                one = true;
                left = i+1;
                right = s.length()-i;
                m = max(m, max(left,right));
            }
        }
        if(one)
        {
            cout<<2*m<<endl;
        }
        else
        {
            cout<<s.length()<<endl;
        }
    }
}