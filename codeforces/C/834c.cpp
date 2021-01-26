/*t = int(input())
while t > 0:
    a,b = map(int, input().split())
    total = a*b
    lo = 0
    hi = total
    found = False
    ans = -1
    while lo <= hi:
        mid = (lo+hi)//2
        if mid*mid*mid == total:
            found = True
            ans = mid
            break
        elif mid*mid*mid < total:
            lo = mid+1
        elif mid*mid*mid > total:
            hi = mid-1

    if found and a%ans == 0 and b%ans == 0:
        print('Yes')
    else:
        print('No')
    t -= 1
*/
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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

void cp()
{
    ll a, b;
    cin >> a >> b;
    ll total = a * b;
    ll lo = 0, hi = 1e6;
    ll ans = -1;
    bool found = false;
    while(lo <= hi)
    {
        ll mid = (hi + lo) / 2;
        // cout<<lo<<" "<<hi<<" "<<mid*mid*mid<<endl;
        if(mid * mid * mid == total)
        {
            ans = mid;
            found = true;
            break;
        }
        else if(mid * mid * mid < total)
            lo = mid + 1;
        else if(mid * mid * mid > total)
            hi = mid - 1;

    }
    if(found && a % ans == 0 && b % ans == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}