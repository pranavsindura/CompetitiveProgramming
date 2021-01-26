#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define fst first
#define snd second
#define rep(i, st, ed) for(int i=st; i<(int)ed; i++)
#define repn(i, st, ed) for(int i=st; i<=(int)ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=(int)st; i--)
#define trav(x, v) for(auto &x: v)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define RANDOM_GEN(st, ed)  uniform_int_distribution<int>(st, ed)(rng)
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define popb pop_back
#define int long long

using ll = long long;
using ld = long double;

using pi = pair<int,int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;

using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;

const int N = 2e5 + 10;
const int M = 1e9 + 7;
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxpq = priority_queue<T>;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << to_string(H) << endl;
  debug_out(T...);
}
#define LOCAL 3
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" << endl, debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void solve()
{
	map<int,int> mp;
	int n;
	cin >> n;
	vi v(n);
	rep(i, 0, n){
		cin >> v[i];
		mp[v[i]] ++;
	}
	ll ans = 0;
	
	rep(i, 0, n){
		mp[v[i]]--;
		ll tans = 0;
		map<int,int> cur;
		rep(j,i+1,n){
			if(v[i] != v[j]){
				ll old = (mp[v[j]] - cur[v[j]]) * cur[v[j]];
				cur[v[j]]++;
				ll nnew = (mp[v[j]] - cur[v[j]]) * cur[v[j]];
				tans += nnew - old;
			}
			if(v[i] == v[j]) ans += tans;
		}
	}
	//cout << ans << endl;
	rep(i, 0, n) mp[v[i]] ++;
	rep(i, 1, n+1){
		ll cnt = mp[i];
		ans += (cnt*(cnt-1)*(cnt-2)*(cnt-3)) / (4*3*2*1);
	}
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout << setprecision(12);
	
	// Write code before test cases 
	
	
	// solving test cases
	
	int tests = 1;
	cin >> tests;
	while(tests--) solve();
	
	
// #ifndef ONLINE_JUDGE
//     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
// #endif
	return 0;
}

