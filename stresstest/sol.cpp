#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
 
using namespace std;
const int maxn = 105;
const int MOD = 1e4+1;
const double eps = 1e-9;
const double INF = 0x3f3f3f3f3f3f3f3f;
const int dir[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
 
struct point {
    double x, y;
    point (double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
}p[maxn];
int N;
 
double distance (point u) {
    double ret = 0;
    for (int i = 0; i < N; i++) {
        double dx = u.x - p[i].x;
        double dy = u.y - p[i].y;
        ret += sqrt(dx * dx + dy * dy);
    }
    return ret;
}
 
double solve () {
    int ti = 1;
    double ret = INF, r = 0.9;
 
    srand(time(NULL));
 
    while (ti--) {
        point u(rand() % MOD, rand() % MOD);
        double step = 1e4;
        double dis = distance(u);
 
        while (step > eps) {
            point v = u;
 
            for (int i = 0; i < 8; i++) {
                point tr(u.x + dir[i][0] * step, u.y + dir[i][1] * step);
                double tmpd = distance(tr);
 
                if (tmpd < dis) {
                    dis = tmpd;
                    v = tr;
                }
            }
 
            u = v;
            step *= r;
            ret = min(ret, dis);
        }
    }
    return ret;
}
 
int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        printf("%.0lf\n", solve());
 
        if (cas)
            printf("\n");
    }
    return 0;
}