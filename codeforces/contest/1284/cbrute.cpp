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
    ll n;
    cin>>n;
    vector<int> perm(n);
    for(int i=0;i<n;i++)
        perm[i]=i+1;
    ll count = 0;
    do{
        ll currcount=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int maxp = *max_element(perm.begin()+i, perm.begin()+j+1);
                int minp = *min_element(perm.begin()+i, perm.begin()+j+1);
                // cout<<j<<" "<<i<<" "<<maxp<<" "<<minp<<endl;
                if(maxp-minp == j-i)
                    currcount++;
            }
        }
        for(int p: perm)
            cout<<p<<" ";
        cout<<": "<<currcount<<endl;
        count += currcount;
    }while(next_permutation(all(perm)));
    cout<<count<<endl;
    return 0;
}