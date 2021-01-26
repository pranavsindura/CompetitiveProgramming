// #include<bits/stdc++.h>
// #define ll long long int
// #define ld long double
// #define pi pair<int,int>
// #define all(x) x.begin(), x.end()
// #define allr(x) x.rbegin(), x.rend()
// #define sz(x) ((int)x.size())
// #define ln(x) ((int)x.length())
// #define mp make_pair
// #define pb push_back
// #define ff first
// #define ss second
// #define endl '\n'
// #define dbg(x) cout<<#x<<": "<<x<<endl
// #define clr(x,v) memset(x, v, sizeof(x))
// #define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// using namespace std;
// const double eps = 1e-9;
// const double PI = acos(-1.0);
// const ll mod = 1e9 + 7;
// const int MAXN = 1e6 + 5;

// void cp()
// {
// 	ll n;
// 	cin>>n;
// 	int p2 = 0, p3 = 0;
// 	while(n%2 == 0)
// 		p2++, n/=2;
// 	while(n%3 == 0)
// 		p3++, n/=3;
// 	if(n>1 || p2 > p3)
// 	{
// 		cout<<-1<<endl;
// 		return;
// 	}
// 	int need = p3 - p2;
// 	p2 += need;
// 	need += p3;
// 	cout<<need<<endl;
// }

// int main()
// {
//     FASTIO;
//     int t;
//     t = 1;
//     cin >> t;
//     while(t--)
//     {
//         cp();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;

    while (test--)
    {
        int count = 0;
        int n;
        cin >> n;
        if (n <= 6) {
            if (n == 1)
                cout << "0\n";
            else if (n == 6)
                cout << "1\n";
            else if (n < 6) {

                if (n % 2 == 0)
                    cout << "-1\n";
                else
                {
                    if (n == 3)
                        cout << "2\n";
                    else
                        cout << "-1\n";
                }
            }
        }
        else
        {
            while (n > 6)
            {
                if (n % 6 == 0) {
                    n = n / 6;
                    count += 1;
                }
                else {
                    n = n * 2;
                    count += 1;
                }
            }

            if (n == 1)
                cout << count << "\n";
            else {
                if (n == 6)
                {
                    cout << count + 1 << "\n";
                }
                else if (n % 2 == 0)
                    cout << "-1\n";
                else
                {
                    if (n == 3)
                        cout << count + 2 << "\n";
                    else
                        cout << "-1\n";
                }
            }
        }
    }

    return 0;
}