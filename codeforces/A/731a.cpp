#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    s = 'a' + s;
    for (int i = 1; i < s.length(); i++)
    {
        sum += min(abs(s[i - 1] - s[i]), 26 - abs(s[i - 1] - s[i]));
    }
    cout << sum;
    return 0;
}