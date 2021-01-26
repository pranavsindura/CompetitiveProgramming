#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;


int main()
{
    FASTIO;
    int n;
    cin >> n;
    string a = "VIBGYOR";
    string ans;
    int pos = 0;
    for(int i = 0; i < n / 7; i++)
    {
        ans += "VIBGYOR";
    }
    int rem = n % 7;
    if(rem < 4)
        a = "GYOR";

    for(int i = 0; i < rem; i++)
    {
        ans += a[i];
    }
    cout<<ans;
    return 0;
}