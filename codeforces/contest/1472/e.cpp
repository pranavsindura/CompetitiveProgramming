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
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> arr(n), b;
    for(int i = 0; i < n; i++)
    {
        int h, w;
        cin >> h >> w;
        arr[i] = make_tuple(h, w, i);
    }

    b = arr;

    vector<int> ans(n, -2);

    // stand, stand
    sort(all(arr), [&](tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<0>(a) < get<0>(b);
    });
    int mn = INT_MAX, idx = -1;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        while(j < i && get<0>(arr[j]) < get<0>(arr[i]))
        {
            if(mn > get<1>(arr[j])) mn = get<1>(arr[j]), idx = get<2>(arr[j]);
            j++;
        }
        if(mn < get<1>(arr[i])) ans[get<2>(arr[i])] = idx;
    }
    // lie, lie
    sort(all(arr), [&](tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<1>(a) < get<1>(b);
    });
    mn = INT_MAX, idx = -1;
    j = 0;
    for(int i = 0; i < n; i++)
    {
        while(j < i && get<1>(arr[j]) < get<1>(arr[i]))
        {
            if(mn > get<0>(arr[j])) mn = get<0>(arr[j]), idx = get<2>(arr[j]);
            j++;
        }
        if(mn < get<0>(arr[i])) ans[get<2>(arr[i])] = idx;
    }


    // stand, lie
    sort(all(arr), [&](tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<0>(a) < get<0>(b);
    });
    sort(all(b), [&](tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<1>(a) < get<1>(b);
    });
    vector<pi> best = {{INT_MAX, -1}, {INT_MAX, -1}};
    j = 0;
    for(int i = 0; i < n; i++)
    {
        while(j < n && get<1>(b[j]) < get<0>(arr[i]))
        {
            best.back() =  min(best.back(), {get<0>(b[j]), get<2>(b[j])});
            sort(all(best));
            j++;
        }
        int x = best.front().ss, y = best.back().ss;
        if(~x)
        {
            if(x != get<2>(arr[i]) && best.front().ff < get<1>(arr[i]))
                ans[get<2>(arr[i])] = x;
        }
        if(~y)
        {
            if(y != get<2>(arr[i]) && best.back().ff < get<1>(arr[i]))
                ans[get<2>(arr[i])] = y;
        }
    }

    // lie, stand
    sort(all(arr), [&](tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<1>(a) < get<1>(b);
    });
    sort(all(b), [&](tuple<int, int, int> x, tuple<int, int, int> y)
    {
        return get<0>(x) < get<0>(y);
    });
    best = {{INT_MAX, -1}, {INT_MAX, -1}};
    j = 0;
    for(int i = 0; i < n; i++)
    {
        while(j < n && get<0>(b[j]) < get<1>(arr[i]))
        {
            best.back() =  min(best.back(), {get<1>(b[j]), get<2>(b[j])});
            sort(all(best));
            j++;
        }
        int x = best.front().ss, y = best.back().ss;
        if(~x)
        {
            if(x != get<2>(arr[i]) && best.front().ff < get<0>(arr[i]))
                ans[get<2>(arr[i])] = x;
        }
        if(~y)
        {
            if(y != get<2>(arr[i]) && best.back().ff < get<0>(arr[i]))
                ans[get<2>(arr[i])] = y;
        }
    }

    for(int x : ans)
        cout << x + 1 << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

