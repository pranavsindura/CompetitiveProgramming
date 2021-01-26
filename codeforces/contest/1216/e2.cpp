#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> pre(1000005);
// vector<ll> pre(1000005);
int main()
{
    pre[0] = 0;
    ll cur=0,prev=0;
    ll digit = 0, pow10 = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        if (i == pow10)
        {
            digit++;
            pow10 *= 10;
        }
        cur = prev + digit;
        prev=cur;
        pre[i] = pre[i-1] + cur;
    }
    // for(int i=1;i<20;i++)
    //     cout<<pre[i]<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>k;
        vector<ll>::iterator it = lower_bound(pre.begin(),pre.end(),k);
        int ind = it-pre.begin();// number in run of ind
        // k - run of(i-1)
        ll pos = k - pre[ind-1];
        // cout<<pos<<endl;
        string s="";
        for(int i=1;s.length()<=pos;i++)
        {
            s += to_string(i);
            // cout<<s<<endl;
        }
        cout<<s[pos-1]<<endl;
        // ll d = k - pre[ind];
        // string s="";
        // for(int i=1;s.length()<d;i++)
        // {
        //     s += to_string(i);
        // }
        // cout<<s<<endl;
        // cout<<s[d];
    }
    return 0;
}
