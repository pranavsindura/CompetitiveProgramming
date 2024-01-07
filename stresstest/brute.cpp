#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &T) {
  int ans = 0;
  deque<int> dq;
  for (int i = 0; i < T.size(); i++) {
    dq.push_back(i);
  }

  vector<int> ops;
  while (!dq.empty()) {
    int index = dq.front();
    dq.pop_front();
    if (T[index] > 0) {
      T[index]--;
      dq.push_back(index);
      ops.push_back(index);
    }
  }

  vector<bool> done(T.size(), false);

  for (int i = ops.size() - 1; i >= 0; i--) {
    if (done[ops[i]])
      continue;
    ans += i + 1;
    done[ops[i]] = true;
  }

  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int &x : A) {
    cin >> x;
  }

  int ans = solve(A);
  cout << ans << endl;
}
