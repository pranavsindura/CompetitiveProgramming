#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int N, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &longest_path) {
  vis[u] = true;

  int my_longest_path = 0;
  for (int v: adj[u]) {
    if (!vis[v]) {
      dfs(v, N, adj, vis, longest_path);
    }
    my_longest_path = max(my_longest_path, longest_path[v] + 1);
  }

  longest_path[u] = my_longest_path;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    adj[u - 1].push_back(v - 1);
  }

  vector<int> longest_path(N);
  vector<bool> vis(N);
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      dfs(i, N, adj, vis, longest_path);
    }
  }

  int ans = *max_element(longest_path.begin(), longest_path.end());
  cout << ans << endl;
}
