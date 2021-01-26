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

int bin(int l, int r, vector<int> &arr, int find)
{
    int lo=l, hi=r;
    int ans = -1;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(arr[mid] <= find)
            ans=mid, lo=mid+1;
        else
            hi=mid-1;
    }
    return ans;
}

int main()
{
    FASTIO;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int,int> hash;
    vector<int> s;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
        hash[arr[i]]++;
    }
    sort(all(arr));
    int mn = n;
    int left=0;
    for(int i=0;i<n;i++)
    {
        int res = bin(0, n-1, arr, 2*arr[i]);
        if(res == -1)
        {
            continue;
        }
        else
        {
            int right = n-res-1;
            mn = min(mn, left+right);
        }
        left++;
    }
    cout<<mn;
    return 0;
}