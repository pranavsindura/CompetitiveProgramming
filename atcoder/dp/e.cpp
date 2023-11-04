// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

long long min_weight(int i, int remaining_value, vector<int> &weights,
                     vector<int> &values, vector<vector<long long>> &dp) {
  if (i >= weights.size()) {
    return remaining_value == 0 ? 0 : INT_MAX;
  }

  if (dp[i][remaining_value] != -1) {
    return dp[i][remaining_value];
  }

  long long ans = INT_MAX;
  if (values[i] <= remaining_value) {
    long long weight_sum_1 =
        weights[i] +
        min_weight(i + 1, remaining_value - values[i], weights, values, dp);
    ans = min(ans, weight_sum_1);
  }

  long long weight_sum_2 =
      min_weight(i + 1, remaining_value, weights, values, dp);
  ans = min(ans, weight_sum_2);

  dp[i][remaining_value] = ans;

  return ans;
}

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> weights(N), values(N);
  vector<vector<long long>> dp(N, vector<long long>(1e5 + 5, -1));
  for (int i = 0; i < N; i++)
    cin >> weights[i] >> values[i];

  int max_value = 0;
  for (int i = 0; i < 1e5 + 5; i++) {
    long long min = min_weight(0, i, weights, values, dp);
    if (min <= W) {
      max_value = max(max_value, i);
    }
  }

  cout << max_value << endl;
}
