#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

int mask(int n)
{
    int rev_msk = 0;
    while(n)
    {
        int d = n % 10;
        if(d == 4 || d == 7)
            rev_msk = rev_msk * 10 + d;
        n /= 10;
    }
    int msk = 0;
    while(rev_msk)
    {
        int d = rev_msk % 10;
        msk = msk * 10 + d;
        rev_msk /= 10;
    }
    return msk;
}

void cp()
{
    int a, b;
    cin >> a >> b;
    bool found = false;
    a++;
    int msk = 0;
    while(!found)
    {
        msk = mask(a);
        if(msk == b){
            found = true;
            break;
        }
        a++;
    }
    cout << a;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}