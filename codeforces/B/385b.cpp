#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define len(x) ((int)x.length())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    string s;
    cin>>s;
    ll ans=0;
    string bear = "bear";
    int c=0, last=0;
    for(int i=0;i<len(s)-3;i++)
    {
        string p = s.substr(i,4);
        if(p == bear)
        {
            c++;
            ll left = i+1-last;
            ll right = len(s)-3-i;
            ans += (left)*(right);
            last=i+1;
        }
    }
    cout<<ans;
    return 0;
}