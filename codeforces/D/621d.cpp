#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

bool comp(complex<double> a, complex<double> b)
{
    if(a.imag() == 0 && b.imag() == 0)
        return a.real() > b.real();
    else if(a.imag() != 0 && b.imag() == 0)
    	return 0;
    else if(a.imag() == 0 && b.imag() != 0)
    	return 1;
    else
    	return a.real() < b.real();
}

void cp()
{
    double a, b, c;
    cin >> a >> b >> c;
    complex<double> x(a, 0), y(b, 0), z(c, 0);

    vector<complex<double>> arr;
    arr.pb(z * log(y) + log(log(x)));
    arr.pb(y * log(z) + log(log(x)));
    arr.pb(log(y) + log(z) + log(log(x)));
    arr.pb(log(y) + log(z) + log(log(x)));
    swap(x, y);
    arr.pb(z * log(y) + log(log(x)));
    arr.pb(y * log(z) + log(log(x)));
    arr.pb(log(y) + log(z) + log(log(x)));
    arr.pb(log(y) + log(z) + log(log(x)));
    swap(x, z);
    arr.pb(z * log(y) + log(log(x)));
    arr.pb(y * log(z) + log(log(x)));
    arr.pb(log(y) + log(z) + log(log(x)));
    arr.pb(log(y) + log(z) + log(log(x)));

    complex<double> mx(DBL_MAX, 1);
    int idx = -1;
    for(int i = 0; i < 12; i++)
        if(comp(arr[i], mx))
            mx = arr[i], idx = i;

    string ans;
    if(idx == 0)       ans = "x^y^z";
    else if(idx == 1)  ans = "x^z^y";
    else if(idx == 2)  ans = "(x^y)^z";
    else if(idx == 3)  ans = "(x^z)^y";
    else if(idx == 4)  ans = "y^x^z";
    else if(idx == 5)  ans = "y^z^x";
    else if(idx == 6)  ans = "(y^x)^z";
    else if(idx == 7)  ans = "(y^z)^x";
    else if(idx == 8)  ans = "z^x^y";
    else if(idx == 9)  ans = "z^y^x";
    else if(idx == 10) ans = "(z^x)^y";
    else               ans = "(z^y)^x";
    cout << ans << endl;
}

// void cp()
// {
//     double x, y, z;
//     cin >> x >> y >> z;
//     vector<double> arr;
//     if(x > 1. || y > 1. || z > 1.)
//     {
//         arr.pb(z * log(y) + log(log(x)));
//         arr.pb(y * log(z) + log(log(x)));
//         arr.pb(log(y) + log(z) + log(log(x)));
//         arr.pb(log(y) + log(z) + log(log(x)));
//         swap(x, y);
//         arr.pb(z * log(y) + log(log(x)));
//         arr.pb(y * log(z) + log(log(x)));
//         arr.pb(log(y) + log(z) + log(log(x)));
//         arr.pb(log(y) + log(z) + log(log(x)));
//         swap(x, z);
//         arr.pb(z * log(y) + log(log(x)));
//         arr.pb(y * log(z) + log(log(x)));
//         arr.pb(log(y) + log(z) + log(log(x)));
//         arr.pb(log(y) + log(z) + log(log(x)));

//         for(double &X : arr)
//             if(isnan(X)) X = -DBL_MAX;
//     }
//     else
//     {
//         arr.pb(pow(x, pow(y, z)));
//         arr.pb(pow(x, pow(z, y)));
//         arr.pb(pow(x, y * z));
//         arr.pb(pow(x, y * z));
//         swap(x, y);
//         arr.pb(pow(x, pow(y, z)));
//         arr.pb(pow(x, pow(z, y)));
//         arr.pb(pow(x, y * z));
//         arr.pb(pow(x, y * z));
//         swap(x, z);
//         arr.pb(pow(x, pow(y, z)));
//         arr.pb(pow(x, pow(z, y)));
//         arr.pb(pow(x, y * z));
//         arr.pb(pow(x, y * z));
//     }

//     string ans;
//     int idx = max_element(all(arr)) - begin(arr);
//     if(idx == 0)       ans = "x^y^z";
//     else if(idx == 1)  ans = "x^z^y";
//     else if(idx == 2)  ans = "(x^y)^z";
//     else if(idx == 3)  ans = "(x^z)^y";
//     else if(idx == 4)  ans = "y^x^z";
//     else if(idx == 5)  ans = "y^z^x";
//     else if(idx == 6)  ans = "(y^x)^z";
//     else if(idx == 7)  ans = "(y^z)^x";
//     else if(idx == 8)  ans = "z^x^y";
//     else if(idx == 9)  ans = "z^y^x";
//     else if(idx == 10) ans = "(z^x)^y";
//     else               ans = "(z^y)^x";
//     cout << ans << endl;
// }

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

