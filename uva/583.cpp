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
const int MAXN = 100005;
int lp[MAXN];
vector<int> prime;

void init()
{
    for(int i = 2; i < MAXN; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.pb(i);
        }
        for(int j = 0; j < sz(prime) && i * prime[j] < MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
    }
}

void cp()
{
    int n;
    cin >> n;
    while(n)
    {
        int temp = abs(n);
        vector<int> fac;
        for(int i = 0; i < sz(prime); i++)
        {
            if(prime[i] > temp)
                break;
            while(temp % prime[i] == 0)
                fac.pb(prime[i]), temp /= prime[i];
        }
        if(temp > 1)
            fac.pb(temp);
        bool pr = false;
        cout << n << " =";
        if(n < 0)
            cout << " -1", pr = true;
        else if(n == 1)
            cout << " 1", pr = true;
        for(int i = 0; i < sz(fac); i++)
        {
            if(pr)
                cout << " x " << fac[i];
            else
            {
                if(i)
                    cout << " x " << fac[i];
                else
                    cout << " " << fac[i];
            }
        }
        cout << endl;
        cin >> n;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}