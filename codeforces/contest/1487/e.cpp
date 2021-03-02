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

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 5e8;
const int MAXN = 1e5 + 5;

void cp()
{
    int n1, n2, n3, n4, m1, m2, m3;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<int> A(n1), B(n2), C(n3), D(n4);
    for(int &x : A)
        cin >> x;
    for(int &x : B)
        cin >> x;
    for(int &x : C)
        cin >> x;
    for(int &x : D)
        cin >> x;

    cin >> m1;
    vector<vector<int>> P(n2);
    for(int i = 0; i < m1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        P[v].push_back(u);
    }
    cin >> m2;
    vector<vector<int>> Q(n3);
    for(int i = 0; i < m2; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Q[v].push_back(u);
    }
    cin >> m3;
    vector<vector<int>> R(n4);
    for(int i = 0; i < m3; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        R[v].push_back(u);
    }


    set<array<int, 2>> st;
    for(int i = 0; i < n1; i++)
        st.insert({A[i], i});

    vector<int> cost1(n2, inf);
    for(int i = 0; i < n2; i++)
    {
        for(int v : P[i])
            st.erase({A[v], v});
        if(!st.empty())
        {
            array<int, 2> F = *st.begin();
            cost1[i] = min(cost1[i], B[i] + F[0]);
        }
        for(int v : P[i])
            st.insert({A[v], v});
    }
    st.clear();

    for(int i = 0; i < n2; i++)
        st.insert({cost1[i], i});

    vector<int> cost2(n3, inf);
    for(int i = 0; i < n3; i++)
    {
        for(int v : Q[i])
            st.erase({cost1[v], v});
        if(!st.empty())
        {
            array<int, 2> F = *st.begin();
            cost2[i] = min(cost2[i], C[i] + F[0]);
        }
        for(int v : Q[i])
            st.insert({cost1[v], v});
    }
    st.clear();

    for(int i = 0; i < n3; i++)
        st.insert({cost2[i], i});

    vector<int> cost3(n4, inf);
    for(int i = 0; i < n4; i++)
    {
        for(int v : R[i])
            st.erase({cost2[v], v});
        if(!st.empty())
        {
            array<int, 2> F = *st.begin();
            cost3[i] = min(cost3[i], D[i] + F[0]);
        }
        for(int v : R[i])
            st.insert({cost2[v], v});
    }
    st.clear();

    int best = *min_element(all(cost3));
    if(best == inf) best = -1;

    cout << best << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
