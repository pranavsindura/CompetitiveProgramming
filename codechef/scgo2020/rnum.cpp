#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define hash make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    vector<int> h =
    {
        7, 17, 19, 23, 29, 47,
        59, 61, 97, 109, 113, 131,
        149, 167, 179, 181, 193, 223,
        229, 233, 257, 263, 269, 313,
        337, 367, 379, 383, 389, 419,
        433, 461, 487, 491, 499, 503,
        509, 541, 571, 577, 593, 619,
        647, 659, 701, 709, 727, 743,
        811, 821, 823, 857, 863, 887,
        937, 941, 953, 971, 977, 983,
        1019, 1021, 1033, 1051, 1063,
        1069, 1087, 1091, 1097, 1103,
        1109, 1153, 1171, 1181, 1193,
        1217, 1223, 1229, 1259, 1291,
        1297, 1301, 1303, 1327, 1367, 1381,
        1429, 1433, 1447, 1487,
        1531, 1543, 1549, 1553, 1567, 1571, 1579, 1583,
        1607, 1619, 1621, 1663, 1697,
        1709, 1741, 1777, 1783, 1789,
        1811, 1823, 1847, 1861, 1873,
        1913, 1949, 1979
    };
    int start = min(n, m);
    int end = max(n, m);
    auto it = lower_bound(all(h), start);
    int ind = it - h.begin();
    for(int i = ind; i < h.size() && h[i] <= end; i++)
    {
        cout << h[i] << " ";
    }
    return 0;
}