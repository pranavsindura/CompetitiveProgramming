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
const double PI = acos(-1.0);
using namespace std;

ll pf(ll n)
{
    ll temp = n;
    ll res = 1;
    if(temp % 2 == 0)
    {
        res *= 2;
        while(temp % 2 == 0)
        {
            temp /= 2;
        }
    }

    for(ll i = 3; i * i <= temp; i += 2)
    {
        if(temp % i == 0)
        {
            res *= i;
            while(temp % i == 0)
            {
                temp /= i;
            }
        }
    }
    if(temp > 2)
        res *= temp;
    return res;
}

int main()
{
    FASTIO;
    ll a;
    cin >> a;
    cout << pf(a);
    return 0;
}