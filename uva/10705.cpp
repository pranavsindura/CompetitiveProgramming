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

void cp()
{
    int k;
    string s;
    ll temp;
    unsigned ll n, mx = 0, mn = 0;
    cin >> k >> s >> temp;

    // we can represent all numbers between mx and mn
    // mx -> all p are 1s
    // mn -> all n are 1s
    for(int i = k - 1; i >= 0; i--)
        if(s[i] == 'p')
            mx |= (1ULL << (k - i - 1));
        else
            mn |= (1ULL << (k - i - 1));

    // if num > mx or num < mn then we cannot represent it.
    if((temp > 0 && temp > mx) || (temp < 0 && (mn < (unsigned ll)(-temp))))
    {
        cout << "Impossible\n";
        return;
    }

    if(temp > 0)
        n = temp;
    // for negative numbers just reverse every thing
    else
    {
        for(char &x : s)
            x = (x == 'p' ? 'n' : 'p');
        swap(mx, mn);
        n = -temp;
    }

    vector<int> ans(k);
    for(int i = k - 1; i >= 0; i--)
        if(s[i] == 'p')
            ans[i] = 1;

    // start from mx and greedily take out the highest power if removing it brings us
    // closer to the answer
    // mx - something = n => something = mx - n
    // to find that something, see the highest power of 2 such that 2^p <= something
    // remove it (if it is 'p' put a 0, if it is 'n' put a 1)
    // also subtract it from something


    unsigned ll diff = mx - n;

    for(int i = 0; i < k; i++)
    {
        if((1ULL << (k - i - 1)) <= diff)
            ans[i] ^= 1, diff -= (1ULL << (k - i - 1));
    }
    if(!diff)
    {
        for(int x : ans)
            cout << x;
        cout << endl;
    }
    else
        cout << "Impossible\n";
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