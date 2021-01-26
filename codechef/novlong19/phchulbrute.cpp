#include <bits/stdc++.h>
#define ll long long int
#define eps 0.000000001
using namespace std;
double dist(pair<ll, ll> p1, pair<ll, ll> p2)
{
    double res = sqrt((p1.first - p2.first) * (p1.first - p2.first) * 1.0 + (p1.second - p2.second) * (p1.second - p2.second) * 1.0);
    return res;
}
double f(pair<ll, ll> p, vector<pair<ll, ll>> s1, vector<pair<ll, ll>> s2, vector<pair<ll, ll>> s3)
{
    double d = DBL_MAX;
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            for (int k = 0; k < s3.size(); k++)
            {
                double curr = dist(p, s1[i]) + dist(s1[i], s2[j]) + dist(s2[j], s3[k]);
                if (d - curr > eps)
                {
                    d = curr;
                }
            }
        }
    }
    return d;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int nl, ml, kl;
        ll a, b, x, y;
        cin >> x >> y;
        cin >> nl >> ml >> kl;
        vector<pair<ll, ll>> n, m, k;
        pair<ll, ll> p = {x, y};
        for (int i = 0; i < nl; i++)
        {
            cin >> a >> b;
            n.push_back(make_pair(a, b));
        }
        for (int i = 0; i < ml; i++)
        {
            cin >> a >> b;
            m.push_back(make_pair(a, b));
        }
        for (int i = 0; i < kl; i++)
        {
            cin >> a >> b;
            k.push_back(make_pair(a, b));
        }
        double d = DBL_MAX;
        double curr = f(p, n, m, k);
        if (d - curr > eps)
            d = curr;
        curr = f(p, m, n, k);
        if (d - curr > eps)
            d = curr;
        cout << setprecision(12) << d << endl;
    }
    return 0;
}