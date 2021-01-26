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
    ll n, k;
    cin >> n >> k;
    bool zero = false;

    while(k != 1 && !zero)
    {
        ll temp = n;
        int mxdig = INT_MIN;
        int midig = INT_MAX;
        while(temp > 0)
        {
            int n = temp % 10;
            mxdig = max(mxdig, n);
            midig = min(midig, n);
            temp /= 10;
            if (!midig || !mxdig)
            {
                zero = true;
                break;
            }
        }
        n += midig * mxdig;
        k--;
    }
    cout << n << endl;
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