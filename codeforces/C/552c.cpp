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
    int w, m;
    cin >> w >> m;

    // Write number m in base w
    deque<int> arr;
    while(m)
    {
        int rem = m % w;
        m /= w;
        arr.push_front(rem);
    }

    int bit = 0, carry = 0;
    bool ok = true;
    // Let's say our left scale as 0 initially and right scale has m
    // We want to balance them
    while(!arr.empty() && ok)
    {
        bit++;

        int last = arr.back();
        arr.pop_back();

        int actual = (last + carry) % w;
        carry = (last + carry) / w;
        // If bit is 0 we can ignore it
        // If bit is 1 we can put w^bit onto the Left scale
        // If bit is w-1 we can put w^bit onto right scale and balance it with a higher power
        // If it is anything else we cannot do anything and answer is not possible
        if(actual == 0 || actual == 1 || actual == w - 1)
        {
            //ok
            if(actual == w - 1 && w > 2)
                carry++;
        }
        else
            ok = false;

        // Use <= 100 bits only
        if(bit > 100)
            ok = false;

        // Apply carry on 0 bit
        if(arr.empty() && carry)
            arr.push_front(0);
    }
    cout << (ok ? "YES" : "NO");
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