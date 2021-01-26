#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n,k,e;
    cin>>n>>k;
    // cout<<n<<" "<<k;
    vector<int> pos, neg;
    for(int i=0;i<n;i++)
    {
        // cout<<i<<" ";
        cin>>e;
        if(e<=0){
            neg.push_back(e);
        }
        else{
            pos.push_back(e);
        }
    }
    int c=0;
    sort(all(neg));
    while(c<k && c<sz(neg))
    {
        neg[c] *= -1;
        // cout<<c<<" ";
        c++;
    }
    k -= c;
    vector<int> arr;
    for(c=0;c<sz(neg);c++)
        arr.push_back(neg[c]);
    for(c=0;c<sz(pos);c++)
        arr.push_back(pos[c]);
    // cout<<k<<endl;
    sort(all(arr));
    if(k>0)
    {
        if(k%2)
            arr[0] *= -1;
    }
    int sum=0;
    for(int x: arr)
        sum+=x;
    cout<<sum;
    return 0;
}