#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 31) - 1;

struct edge {
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}
    bool operator < (edge e) const {return w > e.w;}
};

vector<vector<edge>> adjList;
bool vis[10005], isHotel[10005];
int n, h, hotels[105], dist[105][10005];

void Dijkstra(int src) {
    dist[src][hotels[src]] = 0;

    priority_queue<edge> pq;
    pq.push(edge(-1, hotels[src], 0));

    while (!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (e.w > dist[src][e.to]) continue;

        for (edge ne : adjList[e.to]) {
            if (dist[src][ne.from] + ne.w <= 600 &&
                dist[src][ne.to] > dist[src][ne.from] + ne.w) {

                ne.w = dist[src][ne.to] = dist[src][ne.from] + ne.w;
                pq.push(ne);
            }
        }
    }
}

int BFS() {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 10002; j++) dist[i][j] = INF;

    queue<int> q;
    q.push(0); vis[1] = 1;

    int crnt, dpth = 0, sz = 1;
    for (; !q.empty(); dpth++, sz = q.size()) {
        while (sz--) {
            crnt = q.front(); q.pop();

            Dijkstra(crnt);
            if (dist[crnt][n] != INF) return dpth;

            for (int i = 1; i <= h; i++) {
                if (dist[crnt][hotels[i]] != INF && !vis[hotels[i]]) {
                    vis[hotels[i]] = 1;
                    q.push(i);
                }
            }
        }
    }
    return -1;
}

int main() {
    int m, x, u, v, w;
    hotels[0] = 1;
    while (scanf("%d", &n) && n) {
        scanf("%d", &h);
        memset(isHotel, 0, sizeof isHotel);
        for (int i = 1; i <= h; i++) {
            scanf("%d", &x);
            hotels[i] = x;
            isHotel[x] = 1;
        }

        scanf("%d", &m);
        adjList.clear(); adjList.resize(n+1);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(edge(u, v, w));
            adjList[v].push_back(edge(v, u, w));
        }

        printf("%d\n", BFS());
    }
}