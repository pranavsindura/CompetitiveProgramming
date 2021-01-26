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
bool isprime[10000005];
vector<int> prime;
void init()
{
    prime.pb(2);
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    isprime[0] = false;
    for(int i = 4; i < 10000005; i += 2)
        isprime[i] = false;
    for(int i = 3; i * i < 10000005; i += 2)
    {
        if(isprime[i])
        {
            prime.pb(i);
            for(int j = i * i; j < 10000005; j += i)
            {
                isprime[j] = false;
            }
        }
    }
}
void split(int n)
{
    for(int i = 2; i < n; i++)
    {
        if(isprime[i] && isprime[n - i])
        {
            cout << i << " " << n - i << endl;
            return;
        }
    }
}
int main()
{
    FASTIO;
    int n;
    init();
    while(cin >> n)
    {
        if(n < 8)
            cout << "Impossible." << endl;
        else
        {
            if(n & 1)
            {
                cout << "2 3 ";
                n -= 5;
            }
            else
            {
                cout << "2 2 ";
                n -= 4;
            }
            split(n);
        }
    }
    return 0;
}