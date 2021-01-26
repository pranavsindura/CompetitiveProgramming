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
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll L[MAXN], H[MAXN], P[MAXN];

void cp()
{
    int n, k;
    ll w, AL, BL, CL, DL, AH, BH, CH, DH;
    cin >> n >> k >> w;

    for(int i = 0; i < k; i++)
        cin >> L[i];
    cin >> AL >> BL >> CL >> DL;
    for(int i = 0; i < k; i++)
        cin >> H[i];
    cin >> AH >> BH >> CH >> DH;

    for(int i = k; i < n; i++)
    {
        ll x = ((AL * L[i - 2]) + (BL * L[i - 1]) + CL) % DL + 1;
        ll y = ((AH * H[i - 2]) + (BH * H[i - 1]) + CH) % DH + 1;
        L[i] = x, H[i] = y;
    }

    P[0] = (2 * ((w + H[0]) % mod)) % mod;
    ll ans = P[0];
    for(int i = 1; i < n; i++)
    {

        ll mx_height = 0;
        int j = -1;

        for(int c = 1; c <= w && i - c >= 0; c++)
        {
            if(L[i - c] + w >= L[i])
            {
                if(H[i - c] > mx_height)
                    mx_height = H[i - c], j = i - c;
            }
        }

        if(j == -1)
        {
            // just add
            P[i] = (2 * ((w + H[i]) % mod)) % mod;
            P[i] = (P[i] + P[i - 1]) % mod;
        }
        else
        {
            ll gain = 0, lost = 0;
            if(H[i] > H[j])
            {
                lost = L[j] + w - L[i] + H[j];
                gain = H[i] - H[j] + H[i] + L[i] + w - (L[j] + w) + w;
            }
            else
            {
                lost = H[i];
                gain = 2 * (L[i] + w - (L[j] + w)) + H[i];
            }
            P[i] = (gain - lost + mod) % mod;
            P[i] = (P[i] + P[j]) % mod;
        }
        ans = (ans % mod * P[i] % mod) % mod;
    }

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    time_t t1, t2;
    t1 = clock();
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();

    }
    t2 = clock();
    cout << endl << "time taken: " << (ld) (t2 - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}