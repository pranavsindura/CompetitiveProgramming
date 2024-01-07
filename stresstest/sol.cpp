#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e4 + 5;
const int MOD = 1e9;

int tree[4 * MAXN];

int query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (tl == l && r == tr)
    return tree[v];

  int tm = (tl + tr) >> 1;
  int L = query(v << 1, tl, tm, l, min(r, tm));
  int R = query(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r);

  return L + R;
}

void update(int v, int tl, int tr, int pos) {
  if (tl == tr)
    tree[v]++;
  else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
      update(v << 1, tl, tm, pos);
    } else {
      update(v << 1 | 1, tm + 1, tr, pos);
    }
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
  }
}

int solve(vector<int> &T) {
  int ans = 0;
  vector<int> freq(MAXN, 0), mul(MAXN, 0);

  memset(tree, 0, sizeof tree);

  for (int x : T)
    freq[x]++;

  for (int i = 0; i < MAXN; i++)
    mul[i] = (freq[i] * i) % MOD;

  for (int i = 1; i < MAXN; i++)
    freq[i] = (freq[i] + freq[i - 1]) % MOD;

  for (int i = 1; i < MAXN; i++)
    mul[i] = (mul[i] + mul[i - 1]) % MOD;

  for (int i = T.size() - 1; i >= 0; i--) {
    // all less than T[i] summed
    ans += mul[T[i] - 1];
    ans %= MOD;

    // all greater than or equal to T[i]
    ans += T[i] * (freq[MAXN - 1] - freq[T[i] - 1]);
    ans %= MOD;

    // remove those on the right
    int on_right = query(1, 0, MAXN - 1, T[i], MAXN - 1);
    ans -= on_right;
    ans += MOD;
    ans %= MOD;

    update(1, 0, MAXN - 1, T[i]);
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
