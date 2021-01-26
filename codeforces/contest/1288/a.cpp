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
    int t;
    cin>>t;
    while(t--)
    {
    	int n, d;
        cin>>n>>d;
        bool f = false;
    	for(int i=0;i<=n;i++)
        {
            if(i+ceil((d*1.0)/((i+1)*1.0)) <= n)
            {
                f = true;
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
    return 0;
}