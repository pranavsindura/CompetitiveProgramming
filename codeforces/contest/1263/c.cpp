#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
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
        set<int> s, s2;
        int to = floor(sqrt(n));
        for(int i=1;i<=to+1;i++)
        {
            s.insert(n/i);
        }
        for(int i=0;i<=to;i++)
        {
            s.insert(i);
        }
        cout<<s.size()<<endl;
        for(auto x: s)
            cout<<x<<" ";
        cout<<endl;

    }
    return 0;
}