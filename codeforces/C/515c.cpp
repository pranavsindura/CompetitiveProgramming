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
    ll n, a;
    cin >> n >> a;
    string res;
    while(a)
    {
        int x = a % 10;
        if(x <= 1)
        {
            //pass
        }
        else
        {
            if(x == 4)
                res += "322";
            else if(x == 6)
                res += "53";
            else if(x == 8)
                res += "7222";
            else if(x == 9)
                res += "7332";
            else
                res += to_string(x);
        }
        a /= 10;
    }
    sort(allr(res));
    cout << res;
    return 0;
}