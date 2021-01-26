#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(2*n+1);
        for(int i=0;i<2*n;i++)
            cin>>arr[i], arr[i]--;
        vector<int> s(n), b(n);
        s[0] = (arr[0]==0);
        b[0] = (arr[0]==1);
        for(int i=1;i<n;i++)
        {
            s[i]=s[i-1];
            b[i]=b[i-1];
            if(arr[i])
                b[i]++;
            else
                s[i]++;
        }
        vector<int> diff(n);
        for(int i=0;i<n;i++)
            diff[i]=s[i]-b[i];
        for(int i=0;i<n;i++)
            cout<<diff[i]<<" ";
        cout<<endl;
        map<int,int> l;
        for(int i=0;i<n;i++)
            l[diff[i]]=i+1;
        for(auto x:l)
            cout<<x.first<<"->"<<x.second<<endl;
        cout<<endl;
        s.clear(), b.clear(), diff.clear();
        s[n-1] = (arr[2*n-1]==0);
        b[n-1] = (arr[2*n-1]==1);
        for(int i=n-1-1;i>=0;i--)
        {
            s[i]=s[i+1];
            b[i]=b[i+1];
            if(arr[i+n])
                b[i]++;
            else
                s[i]++;
        }
        for(int i=n-1;i>=0;i--)
            diff[i]=s[i]-b[i];
        for(int i=0;i<n;i++)
            cout<<diff[i]<<" ";
        cout<<endl;
        map<int,int> r;
        for(int i=n-1;i>=0;i--)
            r[diff[i]]=i+1+n;
        for(auto x:r)
            cout<<x.first<<"->"<<x.second<<endl;
        cout<<endl;
        int m=INT_MAX;
        for(auto it=l.begin();it!=l.end();it++)
        {
            if(r[-it->first])
            {
                m = min(m, r[-it->first]-it->second-1);
            }
            if(r[it->first])
            {
                m = min(m, r[it->first]-it->second-1);
            }
        }
        if(m == INT_MAX)
            m = 2*n;
        cout<<m<<endl;
    }
    return 0;
}