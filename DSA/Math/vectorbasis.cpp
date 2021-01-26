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
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
vector<int> basis(20, 0);
int tbasis = 0;

int mask(int x)
{
    int ans = 0;
    for(int i = 0; i < sz(prime); i++)
    {
        int c = 0;
        while(x % prime[i] == 0)
            x /= prime[i], c++;
        if(c & 1)
            ans |= (1 << i);
    }
    return ans;
}
void createBasis(int x)
{
    int msk = mask(x);
    for(int i = 0; i < sz(basis); i++)
    {
        if(msk & (1 << i))
        {
            if(!basis[i])
            {
                basis[i] = msk;
                tbasis++;
                return;
            }
            msk = msk ^ basis[i];
        }
    }
}

int fpow(int x, int y)
{
    int res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * 1LL * x % mod) % mod;
        x = (x % mod * 1LL * x % mod) % mod;
        y = y / 2;
    }
    return res;
}

void cp()
{
    int n, x;
    cin >> n;
    int h[71] = {0};
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        h[x]++;
    }
    for(int i = 1; i <= 70; i++)
    {
        if(h[i])
            createBasis(i);
    }
    cout << fpow(2, n - tbasis) - 1;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}