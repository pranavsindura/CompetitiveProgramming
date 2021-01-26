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
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<vector<int>> fr(n, vector<int>());
        for(int i = 0; i < n; i++)
        {
            fr[i].pb((i-1+n)%n);
            fr[i].pb((i-2+n)%n);
            fr[i].pb((i+1+n)%n);
            fr[i].pb((i+2+n)%n);
            sort(all(fr[i]));
        }
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
        	int res = arr[i];
        	int m = INT_MIN;
        	int ind;
        	for(int j=0;j<sz(fr[i]);j++)
        	{
        		if(arr[fr[i][j]] > m && fr[i][j] != i)
        		{
        			m = arr[fr[i][j]];
        			ind = fr[i][j];
        		}
        	}
        	res += arr[ind];
        	int ind2;
        	m = INT_MIN;
        	for(int j=0;j<sz(fr[ind]);j++)
        	{
        		if(arr[fr[ind][j]] > m && fr[ind][j] != i && fr[ind][j] != ind && binary_search(all(fr[i]), fr[ind][j]))
        		{
        			m = arr[fr[ind][j]];
        			ind2 = fr[ind][j];
        		}
        	}
        	res += arr[ind2];
        	mx = max(mx, res);
        }
        cout<<mx<<endl;
    }
    return 0;
}