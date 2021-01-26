// #include<bits/stdc++.h>
// #define ll long long int
// #define ld long double
// #define pi pair<int,int>
// #define all(x) x.begin(), x.end()
// #define allr(x) x.rbegin(), x.rend()
// #define sz(x) ((int)x.size())
// #define ln(x) ((int)x.length())
// #define mp make_pair
// #define pb push_back
// #define ff first
// #define ss second
// #define endl '\n'
// #define dbg(x) cout<<#x<<": "<<x<<endl
// #define clr(x,v) memset(x, v, sizeof(x))
// #define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// using namespace std;
// const double eps = 1e-9;
// const double PI = acos(-1.0);
// const ll mod = 1e9 + 7;
// const int MAXN = 1e6 + 5;

// void cp()
// {
//     int n;
//     cin >> n;
//     vector<ll> arr(n);
//     for(ll &x : arr)
//         cin >> x;
//     ll pref = 0;
//     ll sum = 0;
//     for(int i = 0; i < n; i++)
//     {
//         sum = (sum + (pref % mod * arr[i] % mod) % mod) % mod;
//         pref = (pref % mod + arr[i] % mod) % mod;
//     }
//     cout << sum;
// }

// int main()
// {
//     FASTIO;
//     int t;
//     t = 1;
//     // cin >> t;
//     while(t--)
//     {
//         cp();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n; 
    vector<long long int> vec(n);
    for(int i=0;i<n;++i) cin >> vec[i];
    vector<long long int> pre(n);
    pre[0] = vec[0];
    for(int i=1;i<n;++i) pre[i] = pre[i-1] + vec[i];
    long long int res = 0;
    for(int i=1;i<n;++i){
        res = ( res%1000000007 + ((long long int)(vec[i]%1000000007)*(pre[i-1]%1000000007))%1000000007 ) % 1000000007;
    }
    cout << res << '\n';
    return 0;
}
