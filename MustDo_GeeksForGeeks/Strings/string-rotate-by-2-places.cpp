/*
    STRING ROTATED BY 2 PLACES
    Check if string a can be formed after rotating b by 2 places
*/

string rotate(string s, bool clockwise)
{
    string temp;
    if(clockwise)
    {
        for(int i = 1; i < ln(s); i++)
            temp += s[i];
        temp += s[0];
    }
    else
    {
        temp += s.back();
        for(int i = 0; i < ln(s) - 1; i++)
            temp += s[i];
    }
    return temp;
}

void cp()
{
    string a, b;
    cin >> a >> b;
    string clockwise_2 = rotate(rotate(b, 1), 1);
    string anti_clockwise_2 = rotate(rotate(b, 0), 0);
    cout << (a == clockwise_2 || a == anti_clockwise_2) << endl;
}
