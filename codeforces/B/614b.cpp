#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Compiler version g++ 6.3.0
bool beaut(string s)
{
    int a = 0, b = 0;
    for(char x : s)
    {
        if(x == '1')
            a++;
        else if(x == '0')
            b++;
    }
    if(a + b == s.length() && a <= 1)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;
    string ans = "1";
    string nb;
    bool zero = false;
    for(string a : arr)
    {
        if(!beaut(a))
            ans = a, nb = a;
        if(a == "0")
            zero = true;
    }
    if(zero)
        ans = "0";
    else
    {
        for(string x : arr)
        {
            if(x == nb)
                continue;
            else
            {
                for(int i = 0; i < (int)x.length() - 1; i++)
                {
                    ans += "0";
                }
            }
        }
    }
    cout << ans;
}