#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
using namespace std;

class CutSticks
{
public:
    double maxKth(vector <int> arr, int C, int K)
    {
        int n = sz(arr);
        sort(allr(arr));
        double lo = eps, hi = 2e9;
        double mid;
        for(int op = 0; op < 1000; op++)
        {
            mid = (lo + hi) / 2;
            ll cuts = C;
            ll cnt = 0;
            for(int i = 0; i < n; i++)
            {
                ll mul = double(arr[i]) / mid;
                ll need = mul;
                if(fabs(arr[i] * 1.0 - mid * double(mul)) <= eps)
                    need--;
                if(need <= cuts)
                {
                    cuts -= need;
                    cnt += mul;
                }
                else
                {
                    cnt += cuts;
                    if(arr[i] * 1.0 - cuts * mid > mid)
                        cnt++;
                    cuts = 0;
                }
            }
            if(cnt >= (ll)K)
                lo = mid;
            else
                hi = mid;
        }
        return mid;
    }
};

int main()
{
    CutSticks cut;
    double res = cut.maxKth(
    			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 15860, 9
    );
    cout << setprecision(12) << fixed << res;
}