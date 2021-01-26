/*
	Implement ATOI
	Takes string as input and returns number
*/

int atoi(string str)
{
    //Your code here
    int n = str.length();
    int res = 0;
    int p = 1;
    bool ok = true;
    for(int i = n - 1; i >= 0; i--)
    {
        if(str[i] >= '0' && str[i] <= '9')
            res = (str[i] - '0') * p + res, p = p * 10;
        else if(str[i] == '-' && i == 0)
            res = -res;
        else
            ok = false;
    }
    if(ok)
        return res;
    else
        return -1;
}