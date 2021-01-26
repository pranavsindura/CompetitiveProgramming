#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> arr;
    int prev = 0;
    for (auto x : s)
    {
        if (x != '+')
        {
            arr.push_back(x - '0');
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        cout << "+" << arr[i];
    }
    return 0;
}