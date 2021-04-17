#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
        
    int ans = 0;
    for(int i=0;i<n-1;i++){
        vector<int> X;
        for(int j=i;j<n;j++){
            X.push_back(arr[j]);
        }
        int mn = 10000000;
        for(int j:X){
            mn = min(j,mn);
        }
        int ind = -1;
        for(int j=0;j<n;j++){
            if(arr[j]==mn){
                ind = j;
                break;
            }
        }
        X.clear();
        for(int j=i;j<=ind;j++){
            X.push_back(arr[j]);
        }
        reverse(all(X));
        vector<int> brr;
        for(int j=0;j<i;j++){
            brr.push_back(arr[j]);
        }
        for(auto j:X){
            brr.push_back(j);
        }
        for(int j=i+X.size();j<n;j++){
            brr.push_back(arr[j]);
        }
        X.clear();
        arr.clear();
        for(int j:brr){
            arr.push_back(j);
        }
        ans+=(ind-i+1);
    }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}