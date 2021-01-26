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

int binl(int l, int r, int find, vector<int> &arr)
{
	int lo=l, hi=r;
	int ans=-1;
	while(lo<=hi)
	{
		int mid = lo + (hi-lo)/2;
		if(arr[mid] <= find)
			ans=mid,lo=mid+1;
		else
			hi=mid-1;
	}
	return ans;
}
// int bing(int l, int r, int find, vector<int> &arr)
// {
// 	int lo=l, hi=r;
// 	int ans=-1;
// 	while(lo<=hi)
// 	{
// 		int mid = lo + (hi-lo)/2;
// 		if(arr[mid] >= find)
// 			ans=mid,lo=mid+1;
// 		else
// 			hi=mid-1;
// 	}
// 	return ans;
// }

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
        multiset<int> s;
        for(int i = 0; i < n; i++)
            cin >> arr[i], s.insert(arr[i]);
        sort(all(arr));
        vector<int> darr(n);
        for(int i=0;i<n;i++)
        	darr[i] = 2*arr[i];
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(2*arr[j] >= arr[i] && 2*arr[i] >= arr[j])
                {
                    c++;
                    // cout<<2*arr[i]<<">="<<arr[j]<<endl;
                    // cout<<arr[i]<<"<="<<2*arr[j]<<endl;
                }
            }
        }
        // cout<<c<<endl;
        // c=0;
        // for(int i=0;i<n;i++)
        // {
        // 	int a = binl(i+1, n-1, darr[i], arr);
        // 	if(a==-1)
        // 		continue;
        // 	a = a-i;
        // 	int b=n-i-1;
        // 	c+= min(a, b);
        // 	// if(it == darr.end())
        // 	// 	continue;
        // 	// else
        // 	// {
        // 	// 	int ind = it-darr.begin();
        // 	// 	if(darr[i] >= arr[ind])
        // 	// 		c++;
        // 	// }
        // }
        cout << c << endl;
    }
    return 0;
}