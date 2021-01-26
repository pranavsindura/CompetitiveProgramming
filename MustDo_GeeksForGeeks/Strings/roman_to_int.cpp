/*
    Convert Roman Numeral to Integer

    If next number is greater than this number then subtract this else add this
*/

map<char, int> val = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

void cp()
{
    string num;
    cin >> num;
    int n = ln(num);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i + 1 < n && val[num[i + 1]] > val[num[i]])
            ans -= val[num[i]];
        else
            ans += val[num[i]];
    }
    cout << ans << endl;
}