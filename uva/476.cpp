#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct point
{
    double x, y;
};
#define point struct point
struct rect
{
    point a, b;
};
#define rect struct rect
bool check(rect r, point p)
{
    if(p.x - r.a.x > eps  && r.b.x - p.x > eps  && r.a.y - p.y > eps && p.y - r.b.y > eps)
        return true;
    else
        return false;

}
int main()
{
    FASTIO;
    point end;
    end.x = 9999.9, end.y = 9999.9;
    char x;
    cin >> x;
    vector<rect> r;
    while(x != '*')
    {
        rect m;
        cin >> m.a.x >> m.a.y >> m.b.x >> m.b.y;
        r.push_back(m);
        cin >> x;
    }
    point p;
    int c = 0;
    cin >> p.x >> p.y;
    while(fabs(p.x - end.x) > eps && fabs(p.y - end.y) > eps)
    {
        bool found = false;
        vector<int> at;
        for(int i = 0; i < (int)r.size(); i++)
        {
            if(check(r[i], p))
            {
                found = true;
                at.push_back(i + 1);
            }
        }
        if(found)
        {
            ++c;
            for(int i : at)
                cout << "Point " << c << " is contained in figure " << i << endl;
        }
        else
            cout << "Point " << ++c << " is not contained in any figure" << endl;
        cin >> p.x >> p.y;
    }
    return 0;
}