#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 2e5 + 5;

// DSU by Size
int parent[MAXN], sz[MAXN];
void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}
bool is_connected(int a, int b)
{
    return find_set(a) == find_set(b);
}
bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(sz[a] < sz[b])
        swap(a, b);
    if(a != b)
        parent[b] = a, sz[a] += sz[b];
    return a != b;
}

// Build log2
int lg[MAXN];
void init()
{
    lg[1] = 0;
    for(int i = 2; i < MAXN; i++)
        lg[i] = lg[i / 2] + 1;
}

using ftype = int;
const int K = 25; // Enough for any array
ftype st[MAXN][K + 1];

ftype combine(ftype L, ftype R)
{
	return __gcd(L, R);
}

void build(vector<ftype> &arr)
{
    int n = sz(arr);
    for(int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for(int j = 1; j <= K; j++)
        for(int i = 0; i + (1 << (j - 1)) < n; i++)
            st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

// Query for idempotent Functions
ftype query(int L, int R)
{
    int j = lg[R - L + 1];
    return combine(st[L][j], st[R - (1 << j) + 1][j]);
}

void cp()
{
	int n, p;
	cin >> n >> p;
	vector<int> A(n);
	for(int &x: A)
		cin >> x;

	vector<int> order;
	for(int i = 0; i < n; i++)
		if(A[i] < p)
			order.push_back(i);
	sort(all(order), [&](int a, int b){ return A[a] < A[b]; });

	make_set(n);
	build(A);

	ll mst = 0;
	for(int x: order) {
		int lo = x, hi = n - 1;
		int right = x;
		while(lo <= hi) {
			int mid = (lo + hi) >> 1;
			int g = query(x, mid);
			if(g == A[x])
				right = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		lo = 0, hi = x;
		int left = x;
		while(lo <= hi) {
			int mid = (lo + hi) >> 1;
			int g = query(mid, x);
			if(g == A[x])
				left = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		// [left, right] satisfy the property
		
		int right_same = x, left_same = x;
		lo = x, hi = right;
		while(lo <= hi) {
			int mid = (lo + hi) >> 1;
			if(find_set(x) == find_set(mid))
				right_same = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		lo = left, hi = x;
		while(lo <= hi) {
			int mid = (lo + hi) >> 1;
			if(find_set(mid) == find_set(x))
				left_same = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		// [left_same, right_same] are already in the same group and can be ignored
		// we can combine rest (right_same, right] and [left, left_same) with x

		for(int y = left; y < left_same; y++)
			if(union_set(y, x))
				mst += A[x];
		for(int y = right_same + 1; y <= right; y++)
			if(union_set(y, x))
				mst += A[x];
	}

	// connect all disconnected groups with edges of weight p
	int groups = 0;
	for(int i = 0; i < n; i++)
		groups += find_set(i) == i;
	mst += (groups - 1) * 1LL * p;

	cout << mst << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}
