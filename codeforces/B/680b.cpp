#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n, a;
    cin >> n >> a;
    a--;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int l = a, r = a, c = 0;
    while(l >= 0 && r < n)
    {
        if(arr[l] && arr[r])
        {
            c++;
            if(l != r)
                c++;
        }

        l--, r++;
    }
    while(l >= 0)
    {
        if(arr[l])
            c++;
        l--;
    }
    while(r < n)
    {
        if(arr[r])
            c++;
        r++;
    }
    cout << c;
    return 0;
}