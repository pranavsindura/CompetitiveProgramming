#include <iostream>
#include <map>
using namespace std;

map<pair<int, int>, int> dp;
int solve(int row, int state, int N) {
  if (row >= N)
    return 1;
  if (dp.count(make_pair(row, state))) {
    return dp[make_pair(row, state)];
  }
  int occ = 0;
  int ans = 0;
  for (int last = state, i = row - 1; i >= 0; i--, last /= N) {
    int pos = last % N;
    occ |= (1 << pos);
    int diff = row - i;
    if (pos + diff < N) {
      occ |= (1 << (pos + diff));
    }
    if (pos - diff >= 0) {
      occ |= (1 << (pos - diff));
    }
  }

  for (int i = 0; i < N; i++) {
    if (!((occ >> i) & 1)) {
      ans += solve(row + 1, state * N + i, N);
    }
  }

  return dp[make_pair(row, state)] = ans;
}

int main() {
  int n;
  cin >> n;
  int ans = solve(0, 0, n);
  cout << ans << endl;
}
