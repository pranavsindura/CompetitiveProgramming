#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    string s1, s2;
    cin >> s1 >> s2;
    vector<char> left, right, rem;
    int pos = 0;
    for(; s1[pos] != '|'; pos++)
        left.push_back(s1[pos]);
    pos++;
    for(; pos < s1.length(); pos++)
        right.push_back(s1[pos]);
    for(char x : s2)
        rem.push_back(x);
    int ln = left.size(), rn = right.size(), remn = rem.size();
    int total = ln + rn + remn;
    if(total % 2)
    {
        cout << "Impossible";
        return 0;
    }
    else
    {
        int half = total / 2;
        if(ln > half || rn > half)
        {
            cout << "Impossible";
            return 0;
        }
        pos = 0;
        while(ln < half)
        {
            left.push_back(rem[pos]);
            ln++, pos++;
        }
        while(rn < half)
        {
            right.push_back(rem[pos]);
            rn++, pos++;
        }
        for(char x: left)
        	cout<<x;
        cout<<"|";
        for(char x: right)
        	cout<<x;
    }
    return 0;
}