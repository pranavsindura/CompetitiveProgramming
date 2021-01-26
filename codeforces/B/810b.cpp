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
    int n, f;
    cin>>n>>f;
    vector<ll> k(n), l(n);
    for(int i=0;i<n;i++)
    	cin>>k[i]>>l[i];
    ll total = 0;
    vector<int> cand;
    for(int i=0;i<n;i++)
    {
    	if(k[i]<l[i])
    		cand.push_back(i);
    	else{
    		total += l[i];
    	}
    }
    sort(all(cand), [&](int a, int b){return min(2*k[a], l[a])-min(k[a],l[a]) > min(2*k[b],l[b])-min(k[b],l[b]);});
    for(int i=0;i<sz(cand);i++)
    {
    	if(f)
    	{
    		total += min(2*k[cand[i]], l[cand[i]]);
    		f--;
    	}
    	else{
    		total += k[cand[i]];
    	}
    }
    cout<<total;
    return 0;
}