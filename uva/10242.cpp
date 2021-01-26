#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define test int t;cin>>t;while(t--)
const double PI = acos(-1.0);
using namespace std;
struct point
{
    double x, y;
};
#define point struct point
int main()
{
    FASTIO;
    point a, b, c, d;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y) == 8)
    {
        double x, y;
        if(a.x == c.x && a.y == c.y)
            x = (b.x + d.x) - a.x, y =  (b.y + d.y) - a.y;
        else if(a.x == d.x && a.y == d.y)
            x = (b.x + c.x) - a.x, y = (b.y + c.y) - a.y;
        else if(b.x == c.x && b.y == c.y)
            x = (a.x + d.x) - b.x, y = (a.y + d.y) - b.y;
        else
            x = (a.x + c.x) - b.x, y = (a.y + c.y) - b.y;
        printf("%.3lf %.3lf\n", x, y);
    }
    return 0;
}