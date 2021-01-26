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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);

bool overlap(pii a, pii b)
{
    if((a.ff <= b.ff && a.ss >= b.ff) || (b.ff <= a.ff && b.ss >= a.ff))
        return true;
    else
        return false;
}

void cp()
{
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    int ming = a-b;
    ming *= n;
    int maxg = a+b;
    maxg *= n;
    int mintotal = c-d;
    int maxtotal = c+d;
    if(overlap(mp(ming, maxg), mp(mintotal, maxtotal)))
        cout<<"Yes\n";
    else
        cout<<"No\n";
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