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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n, k, l, r, sk, sall;
    cin >> n >> k >> l >> r >> sall >> sk;
    vector<int> arr(n);
    int d = sk / k;
    int rem = sk % k;
    for(int i = 0; i < k; i++)
    {
        arr[i] = d;
        if(rem > 0)
            arr[i]++, rem--;
    }
    if(n != k)
    {
        d = (sall - sk) / (n - k);
        rem = (sall - sk) % (n - k);
        for(int i = k; i < n; i++)
        {
            arr[i] = d;
            if(rem > 0)
                arr[i]++, rem--;
        }
    }
    for(int x : arr)
        cout << x << " ";
    return 0;
}