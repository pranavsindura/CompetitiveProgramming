#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define test int t;cin>>t;while(t--)
const double PI = acos(-1.0);
using namespace std;
int main()
{
    FASTIO;
    int d, h, v, e;
    cin >> d >> h >> v >> e;
    double r = (d * 1.0) / 2.0;
    double rain = PI * r * r * e;
    double drink = v;
    double init = PI * r * r * h;
    if(rain - drink > eps)
        cout << "NO";
    else
    {
        cout << "YES\n";
        double t = init / (drink - rain);
        cout << fixed << setprecision(10) << t;
    }
    return 0;
}