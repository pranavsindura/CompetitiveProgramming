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

struct r
{
    double x1, x2, y1, y2;
};
#define r struct r

r pt[1000005];

bool check(r &rect, int x, int y)
{
    if(x * 1.0 > rect.x1 && x * 1.0 < rect.x2 && y * 1.0 > rect.y1 && y * 1.0 < rect.y2)
        return true;
    else
        return false;
}

int main()
{
    FASTIO;
    int a, x, y;
    cin >> a >> x >> y;
    pt[1].x1 = -(a * 1.0) / 2.0;
    pt[1].y1 = 0;
    pt[1].x2 = (a * 1.0) / 2.0;
    pt[1].y2 = a;
    pt[2].x1 = -(a * 1.0) / 2.0;
    pt[2].y1 = a;
    pt[2].x2 = (a * 1.0) / 2.0;
    pt[2].y2 = 2 * a;
    bool s = false;
    for(int i = 3; i < 1000004; i++)
    {
        if(s)
        {
            pt[i].x1 = -(a * 1.0) / 2.0;
            pt[i].y1 = pt[i - 1].y1 + a;
            pt[i].x2 = (a * 1.0) / 2.0;
            pt[i].y2 = pt[i - 1].y2 + a;
        }
        else
        {
            pt[i].x1 = -a;
            pt[i].y1 = pt[i - 1].y1 + a;
            pt[i].x2 = 0;
            pt[i].y2 = pt[i - 1].y2 + a;

            pt[i + 1].x1 = 0;
            pt[i + 1].y1 = pt[i].y1;
            pt[i + 1].x2 = a;
            pt[i + 1].y2 = pt[i].y2;
            i++;
        }
        s = !s;
    }
    for(int i = 1; i < 1000004; i++)
    {
        if(check(pt[i], x, y))
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}