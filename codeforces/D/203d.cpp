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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ld eps = 1e-10;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

// SIMULATION

void cp()
{
    int a, b, m, vx, vy, vz;
    cin >> a >> b >> m >> vx >> vy >> vz;

    ld t = - (ld)m / (ld)vy;
    ld steps = t / 1000000.0;
    ld x = a / 2.0, y = m, z = 0;
    for(int itr = 0; itr < 1000000; itr++)
    {
        x += vx * steps, y += vy * steps, z += vz * steps;
        if(y < eps)
            break;
        if(x < eps)
            x *= -1, vx *= -1;
        else if(x > a)
            x = a - (x - a), vx *= -1;
        if(z < eps)
            z *= -1, vz *= -1;
        else if(z > b)
            z = b - (z - b), vz *= -1;
    }
    dblout(10);
    cout << x << " " << z << endl;
}

// MATH

// void cp()
// {
//     int a, b, m, vx, vy, vz;
//     cin >> a >> b >> m >> vx >> vy >> vz;

//     ld t = - (ld)m / (ld)vy;
//     // X coordinate
//     int sg = (vx >= 0 ? 1 : 0);
//     ld sx = abs(vx * t);
//     int mul = sx / (ld)a;
//     ld off = sx - mul * a;
//     ld x = a / 2.0;

//     if((mul & 1) == sg)
//     {
//         if(off <= a / 2.0) // go left
//             x -= off;
//         else
//             x = off - a / 2.0; // go right
//     }
//     else
//     {
//         if(off <= a / 2.0) // go right
//             x += off;
//         else
//             x = a - (off - a / 2.0); // go left
//     }

//     // Z coordinate
//     ld sz = vz * t;
//     mul = sz / (ld)b;
//     off = sz - mul * b;
//     ld z = 0;
//     if(mul & 1)
//         // go down
//         z = b * 1.0 - off;
//     else
//         // go up
//         z = off;

//     dblout(15);
//     cout << x << " " << z << endl;
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