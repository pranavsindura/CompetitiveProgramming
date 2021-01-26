#include <bits/stdc++.h>
#define ll long long int
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
int main()
{
    FASTIO;
    int n, x;
    cin >> n;
    int p1, p2;
    cin >> p1;
    set<int> s;
    for (int i = 0; i < p1; i++)
    {
        cin >> x;
        s.insert(x);
    }
    cin >> p2;
    for (int i = 0; i < p2; i++)
    {
        cin >> x;
        s.insert(x);
    }
    if (s.size() == n)
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";
    return 0;
}