#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n;
  long long d;
  cin >> n >> d;

  vector<long long> starts(n);

  for (long long &x : starts) {
    cin >> x;
  }

  sort(starts.begin(), starts.end());

  int l = 0, r = starts.back() + d, p = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    bool ok = true;
    long long last = starts.front();
    for (int i = 1; i < n; i++) {
      long long next = max(last + m, starts[i]);
      if (next > starts[i] + d) {
        ok = false;
      }
      last = next;
    }

    if (ok) {
      p = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  cout << p << endl;

  return 0;
}
