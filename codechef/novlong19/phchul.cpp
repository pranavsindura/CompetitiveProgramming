#include <bits/stdc++.h>
#define ll long long int
#define eps 0.000000001
using namespace std;
double eucdist(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) * 1.0 + (p1.second - p2.second) * (p1.second - p2.second) * 1.0);
}
vector<pair<ll, ll>> find_short(vector<pair<ll, ll>> s1, vector<pair<ll, ll>> s2)
{
    vector<pair<ll, ll>> ans;
    for (int i = 0; i < s1.size(); i++)
    {
        double d = DBL_MAX;
        pair<ll, ll> res;
        for (int j = 0; j < s2.size(); j++)
        {
            double curr = eucdist(s1[i], s2[j]);
            if (d - curr > eps)
            {
                d = curr;
                res = s2[j];
            }
        }
        ans.push_back(res);
    }
    return ans;
}

vector<pair<int, double>> find_mid_short(vector<pair<ll, ll>> n, vector<pair<ll, ll>> m, vector<pair<ll, ll>> mk)
{
    vector<pair<int, double>> ans;
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = 0; j < m.size(); j++)
        {
            ans.push_back({i, eucdist(n[i], m[j]) + eucdist(m[j], mk[j])});
        }
    }
    return ans;
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
        vector<pair<ll, ll>> mk = find_short(m, k);
        vector<pair<ll, ll>> nk = find_short(n, k);
        vector<pair<int, double>> nmk = find_mid_short(n, m, mk);
        vector<pair<int, double>> mnk = find_mid_short(m, n, nk);
        double d = DBL_MAX;
        for (int i = 0; i < nmk.size(); i++)
        {
            double curr = eucdist(p, n[nmk[i].first]) + nmk[i].second;
            if (d - curr > eps)
                d = curr;
        }
        for (int i = 0; i < mnk.size(); i++)
        {
            double curr = eucdist(p, m[mnk[i].first]) + mnk[i].second;
            if (d - curr > eps)
                d = curr;
        }
        cout << setprecision(12) << d << endl;
    }
    return 0;
}