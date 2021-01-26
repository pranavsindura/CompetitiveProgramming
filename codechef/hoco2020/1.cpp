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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

string add(string str1, string str2)
{
    string str = "";
    int n1 = ln(str1), n2 = ln(str2);
    reverse(all(str1));
    reverse(all(str2));

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        str.push_back(carry + '0');
    reverse(all(str));
    return str;
}

int main()
{
    FASTIO;
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i < ln(s); i++)
    {
        res = (res * 10 + (int)(s[i] - '0')) % 4;
    }
    if(res == 0)
    {
        cout << s;
    }
    else if(res == 1)
    {
        cout << 1;
    }
    else if(res == 2)
    {
        s = add("1", s);
        cout << s;
    }
    else
    {
        cout << 0;
    }
    return 0;
}