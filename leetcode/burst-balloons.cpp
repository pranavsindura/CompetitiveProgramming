#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dp[305][305];
int solve(int i, int j, vector<int> &A) {
  if (j - i + 1 <= 2) {
    return 0;
  }
  if (j - i + 1 == 3) {
    return A[i + 1] * A[i] * A[j];
  }

  int &ret = dp[i][j];
  if (~ret) {
    return ret;
  }

  int best = 0;
  for (int k = i + 1; k < j; k++) {
    int curr = A[k] * A[i] * A[j] + solve(i, k, A) +
               solve(k, j, A);
    best = max(best, curr);
  }

  return ret = best;
}

int main() {
  int n;
  cin >> n;

  vector<int> A;
  A.push_back(1);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    A.push_back(x);
  }
  A.push_back(1);

  memset(dp, -1, sizeof(dp));
  int ans = solve(0, A.size() - 1, A);

  cout << ans << endl;
}
