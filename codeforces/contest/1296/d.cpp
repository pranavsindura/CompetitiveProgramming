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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    vector<int> reduced;
    for(int i = 0; i < n; i++)
    {
        int temp = h[i];
        int mul = temp / (a + b);
        int rem = temp % (a + b);
        if(rem == 0)
            mul--;

        int actual = mul * (a + b);
        rem = h[i] - actual;
        rem -= a;
        if(rem <= 0)
            reduced.push_back(0);
        else
        {
            reduced.push_back((rem + a - 1) / a);
        }
    }
    sort(all(reduced));
    int cnt = 0;
    ll sum = 0;
    for(int i = 0; i < sz(reduced); i++)
    {
        if(sum + reduced[i] > 1LL * k)
            break;
        else
        {
            sum += reduced[i];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}