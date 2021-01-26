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
vector<pair<ll, ll>> arr(100005);
bool isprime[20000005];
void init()
{
    memset(isprime, true, sizeof(isprime));
    for(ll i = 4; i <= 20000000; i+=2)
    	isprime[i] = false;
    for(ll i = 3; i * i <= 20000000; i+=2)
    {
        if(isprime[i])
        {
            for(ll j = i * i; j <= 20000000; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    int k = 1;
    for(ll i = 3; i <= 20000000 && k < sz(arr); i += 2)
    {
        if(isprime[i] && isprime[i + 2])
            arr[k++] = mp(i, i + 2);
    }

}
int main()
{
    FASTIO;
    init();
    int n;
    while(cin >> n)
    {
        cout << "(" << arr[n].ff << ", " << arr[n].ss << ")" << endl;
    }
    // cout << "{\n";
    // for(int i = 1; i <= 100000; i++)
    // {
    //     cout << "mp(" << arr[i].ff << ", " << arr[i].ss << "), \n";
    // }
    // cout << "}";
    return 0;
}