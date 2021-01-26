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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " : " << a << endl;
	err(++it, args...);
}
const double PI = acos(-1.0);

int pref(int x)
{
    switch(x%4)
    {
        case 0: return x;
        case 3: return 0;
        case 1: return 1;
        case 2: return x+1;
    }
}

void cp()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    // vector<ll> pref(n+1, 0);
    for(int &x: arr)
        cin>>x;
    ll m = 0;
    // for(int i=1;i<=n;i++)
    // {
    //     pref[i] = pref[i-1]^i;
    // }
    for(int i=1;i<=n;i++)
    {
        int rem = n%i;
        int div = n/i;
        if(div&1)
            m = m^pref(i-1);
        m = m^pref(rem);
    }
    for(int x: arr)
        m = m^x;
    cout<<m;
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