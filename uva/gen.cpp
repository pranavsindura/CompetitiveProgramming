#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int get(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

int main()
{
    FASTIO;
    srand(time(NULL));
    int t = 20;
    while(t--)
    {
        int n = get(2, 100);
        cout << n << endl;
        int h = get(0, n);
        cout << h << " ";
        set<int> hotel;
        while(sz(hotel) < h)
            hotel.insert(get(1, n));

        for(int x : hotel)
            cout << x << " ";
        cout << endl;

        int m = get(1, n * (n - 1) / 2);
        cout << m << endl;
        while(m--)
        {
            int u = get(1, n), v = get(1, n);
            if(u != v)
                cout << u << " " << v << " " << get(1, 600) << endl;
            else
                m++;
        }
    }
    cout << 0 << endl;
    return 0;
}