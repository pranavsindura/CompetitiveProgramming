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
const int MAXN = 1e3 + 5;

int is_hill(int a, int b, int c)
{
    return a < b && b > c;
}

int is_valley(int a, int b, int c)
{
    return a > b && b < c;
}

int sumN, sumQ;
void cp()
{
    int N, Q;
    cin >> N;
    assert(N >= 2 && N <= 1e5);
    sumN += N;
    assert(sumN <= 1e6);
    vector<int> A(N);
    for(int &x : A)
        cin >> x, assert(x >= 1 && x <= 1e9);
    cin >> Q;
    assert(Q >= 1 && Q <= 1e5);
    vector<int> Type(Q), U(Q), V(Q);
    for(int &x : Type)
        cin >> x;
    for(int &x : U)
        cin >> x;
    for(int &x : V)
        cin >> x;

    vector<int> L(N), R(N);
    iota(all(L), -1);
    iota(all(R), 1);

    auto valid = [&](int idx)
    {
        return idx >= 0 && idx < N;
    };

    auto contrib = [&](int idx)
    {
        if(!valid(idx)) return 0;
        if(!valid(L[idx]) || !valid(R[idx])) return 0;
        return is_hill(A[L[idx]], A[idx], A[R[idx]]) + is_valley(A[L[idx]], A[idx], A[R[idx]]);
    };

    int count_hill_valley = 0;

    for(int i = 0; i < N; i++)
        count_hill_valley += contrib(i);

    for(int i = 0; i < Q; i++)
    {
        assert(Type[i] >= 1 && Type[i] <= 2);
        assert(U[i] >= 1 && U[i] <= N);
        if(Type[i] == 1)
            assert(V[i] >= 1 && V[i] <= 1e9);
        else
            assert(V[i] >= 1 && V[i] <= N && U[i] != V[i]);

        if(Type[i] == 1)
        {
            U[i]--;
            count_hill_valley -= contrib(L[U[i]]);
            count_hill_valley -= contrib(U[i]);
            count_hill_valley -= contrib(R[U[i]]);
            A[U[i]] = V[i];
            count_hill_valley += contrib(L[U[i]]);
            count_hill_valley += contrib(U[i]);
            count_hill_valley += contrib(R[U[i]]);
        }
        else
        {
            U[i]--, V[i]--;
            count_hill_valley -= contrib(L[U[i]]);
            count_hill_valley -= contrib(U[i]);
            count_hill_valley -= contrib(R[U[i]]);
            if(!valid(L[U[i]])) // left most
            {
                // nothing to be added
                L[R[U[i]]] = -1;
            }
            else if(!valid(R[U[i]])) // right most
            {
                // nothing to be added
                R[L[U[i]]] = N;
            }
            else // somewhere in middle
            {
                R[L[U[i]]] = R[U[i]];
                L[R[U[i]]] = L[U[i]];
                count_hill_valley += contrib(L[U[i]]);
                count_hill_valley += contrib(R[U[i]]);
            }

            count_hill_valley -= contrib(V[i]);
            count_hill_valley -= contrib(R[V[i]]);
            L[U[i]] = V[i];
            R[U[i]] = R[V[i]];
            if(valid(R[V[i]]))
                L[R[V[i]]] = U[i];
            R[V[i]] = U[i];

            count_hill_valley += contrib(V[i]);
            count_hill_valley += contrib(U[i]);
            count_hill_valley += contrib(R[U[i]]);
        }
        cout << count_hill_valley << " ";
    }
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    assert(t >= 1 && t <= 30);
    while(t--)
    {
        cp();
    }
    return 0;
}
