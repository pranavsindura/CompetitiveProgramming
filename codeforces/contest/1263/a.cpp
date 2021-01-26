#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(all(a));
        int ans = 0;
        if(a[0] == a[1] && a[1] == a[2])
        {
        	a[1]--;
 			a[0]--;
 			ans++;
        }
        int steps = a[1]-a[0];
        ans += steps;
        a[1] -= steps;
        a[2] -= steps;
        sort(all(a));
        if(a[0]+a[1] > a[2])
        {
        	steps = a[0] + a[1] - a[2];
        	if(steps&1)
        		steps++;
        	int h = steps/2;
        	ans += h;
        	a[0] -= h;
        	a[1] -= h;
        }
        ans += a[0]+a[1];
        cout<<ans<<endl;
    }
    return 0;
}