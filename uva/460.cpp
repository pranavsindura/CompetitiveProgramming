#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct point
{
    int x, y;
};
#define point struct point
int main()
{
    FASTIO;
    char g;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        point a, b, c, d;
        scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
        scanf("%d %d %d %d", &c.x, &c.y, &d.x, &d.y);
        int i, j, k, l;
        i = max(a.x, c.x);
        j = max(a.y, c.y);
        k = min(b.x, d.x);
        l = min(b.y, d.y);
        if(i >= k || j >= l)
            printf("No Overlap\n");
        else
            printf("%d %d %d %d\n", i, j, k, l);
        if(t)
            printf("\n");
    }
    return 0;
}