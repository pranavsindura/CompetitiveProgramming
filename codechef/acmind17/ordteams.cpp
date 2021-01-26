#include <bits/stdc++.h>
using namespace std;
struct p
{
    int a, b, c;
};
#define p struct p
bool check(p s1, p s2)
{
    //is s1 better than s2
    if (s1.a < s2.a || s1.b < s2.b || s1.c < s2.c || (s1.a == s2.a && s1.b == s2.b && s1.c == s2.c))
        return false;
    else
        return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        p s1, s2, s3;
        cin >> s1.a >> s1.b >> s1.c >> s2.a >> s2.b >> s2.c >> s3.a >> s3.b >> s3.c;
        bool f = false;
        //1 2 3
        if (check(s2, s1) && check(s3, s2) && check(s3, s1))
            f = true;
        //1 3 2
        if (check(s3, s1) && check(s2, s3) && check(s2, s1))
            f = true;
        //2 1 3
        if (check(s1, s2) && check(s3, s1) && check(s3, s2))
            f = true;
        // 2 3 1
        if (check(s3, s2) && check(s1, s3) && check(s1, s2))
            f = true;
        //3 1 2
        if (check(s1, s3) && check(s2, s1) && check(s2, s3))
            f = true;
        //3 2 1
        if (check(s2, s3) && check(s1, s2) && check(s1, s3))
            f = true;
        if(f)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}