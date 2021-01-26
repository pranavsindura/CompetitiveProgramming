#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) * 1.0 + (y1 - y2) * (y1 - y2) * 1.0);
}

int main()
{
    FASTIO;
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    double d = 0;
    for(int i = 0; i < n - 1; i++)
    {
        d += dist(p[i].first, p[i].second, p[i + 1].first, p[i + 1].second);
    }
    d *= k * 1.0;
    d /= 50.0;
    cout << fixed << setprecision(10) << d;
    return 0;
}