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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll median;
priority_queue<ll> pq_left;
priority_queue<ll, vector<ll>, greater<ll>> pq_right;

void insert(ll x)
{
    if(sz(pq_left) > sz(pq_right))
    {
        if(x < median)
        {
            // put in left
            // and move top element from left to right as it will be pushed because of new median
            ll left = pq_left.top();
            pq_left.pop();
            pq_right.push(left);
            pq_left.push(x);
            median = pq_left.top();
        }
        else
        {
            // put in right
            pq_right.push(x);
            median = pq_left.top();
        }
    }
    else if(sz(pq_left) < sz(pq_right))
    {
        if(x < median)
        {
            // put in left
            pq_left.push(x);
            median = pq_left.top();
        }
        else
        {
            // put in right
            // and move top element from right to left as it will be pushed because of new median
            ll right = pq_right.top();
            pq_right.pop();
            pq_left.push(right);
            pq_right.push(x);
            median = pq_left.top();
        }
    }
    else
    {
        if(x < median)
        {
            // put in left
            pq_left.push(x);
            median = pq_left.top();
        }
        else
        {
            // put in right
            pq_right.push(x);
            median = pq_right.top();
        }
    }
}

void cp()
{
    while(!pq_left.empty())
        pq_left.pop();
    while(!pq_right.empty())
        pq_right.pop();
    median = 0;
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    ll sum = 1;
    insert(1);
    for(int i = 2; i <= n; i++)
    {
        ll g = (a * median) % mod;
        g = (g + (b * i) % mod) % mod;
        g = (g + c) % mod;
        sum = sum + g;
        insert(g);
    }

    cout << sum << endl;
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