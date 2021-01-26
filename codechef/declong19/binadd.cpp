#include <bits/stdc++.h>
#define ll long long int
#define M 1001
#define N 1000001
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define bitm bitset<M>
#define bitn bitset<N>
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;

int f(string x, string y)
{
    bitm a, b;
    a = bitm(x);
    b = bitm(y);
    bitm m = a & b, n = ~(a ^ b);
    cout<<m<<endl<<n<<endl;
    int c = 0;
    while(b.count())
    {
        bitm u = a ^ b;
        bitm v = a & b;
        a = u;
        b = v << 1;
        c++;
    }
    return c;
}

int f2(string x, string y)
{
    bitn a = bitn(x), b = bitn(y), m = a & b, n = ~(a ^ b);
    dbg(m);dbg(n);
    if(!b.count())
    {
        return 0;
    }
    else if(!a.count() || !m.count())
    {
        return 1;
    }
    int c = 0;
    int maxc = INT_MIN;
    bool f = true;
    for(int i = 0; i < N; i++)
    {
        if(f)
        {
            if(m.test(i))
            {
                f = false;
            }
        }
        else
        {
            if(n.test(i))
            {
            	cout<<i<<": "<<c+2<<endl;
                maxc = max(maxc, c + 2);
                f = true;
                c = 0;
                i--;
            }
            else
            {
                c++;
            }
        }

    }
    return maxc;
}

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        string x, y;
        cin >> x >> y;
        if(max(x.length(), y.length()) <= 1000)
        {
            cout << f(x, y) << endl;
        }
        else
        {
        	cout << f2(x, y) << endl;
        }
    }
    return 0;
}