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

void bsort(vector<int> &arr, int k)
{
    bool sw = false, ok = true;
    int count = 0, n = sz(arr);
    for(int i = 0; i < n; i++)
    {
        int ind = -1, mx = INT_MIN;
        for(int j = i; j < i + (k - count + 1) && j < n; j++)
        {
            if(arr[j] > mx)
            {
                mx = arr[j];
                ind = j;
            }
        }
        //cout<<ind<<" ";
        while(ind > i && count < k)
        {
            swap(arr[ind], arr[ind - 1]);
            ind--;
            count++;
        }
    }
}

int main()
{
    FASTIO;
    ll a, k;
    cin >> a >> k;
    vector<int> arr;
    while(a)
    {
        arr.pb(a % 10);
        a /= 10;
    }
    reverse(all(arr));
    bsort(arr, k);
    for(int x : arr)
        cout << x;
    return 0;
}