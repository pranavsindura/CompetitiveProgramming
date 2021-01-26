#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
	int n,k,x;
	cin>>n>>k;
	vector<int> arr(1000,0);
	for(int i=0;i<n;i++){
		cin>>x;
		arr[x]++;
	};
	int v=0;
	for(int i=1;i<sz(arr);i++)
	{
		if(arr[i]){
			v=i;
		}
		else
		{
			if(k)
			{
				v=i;
				k--;
			}
			else
				break;
		}

	}
	cout<<v<<endl;
}

int main()
{
    FASTIO;
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
    	cp();
    }
    return 0;
}