/*
	Given a string S containing only digits, Your task is to complete the function genIp()
	which returns a vector containing all possible combination of valid IPv4 ip address
	and takes only a string S as its only argument.

	Valid IPv4 address
	1. Only 3 dots
	2. Each number is in range [0, 255]
	3. Numbers do not contain leading zeros
*/

/*
	Approach 1 - O(N^4)
		Can be done with an iterative approach
		Pick the positions for dots
		and then check validity of each number around the dots
		Form answer
*/
bool valid(string &s)
{
    int n = s.length();
    // Should not empty and should contain at most 3 numbers
    if(s.empty() || n > 3)
        return false;
    // should not have leading zeros
    if(s[0] == '0' && n > 1)
        return false;
    // s must be a number in range [0, 255]
    int num = 0;
    for(char x : s)
        num = num * 10 + (x - '0');
    return num >= 0 && num <= 255;
}

vector<string> genIp(string &s)
{
    vector<string> ans;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                //place . after [0, i], [i+1, j], [j+1, k] letters
                string a, b, c, d;
                for(int l = 0; l <= i; l++)
                    a += s[l];
                for(int l = i + 1; l <= j; l++)
                    b += s[l];
                for(int l = j + 1; l <= k; l++)
                    c += s[l];
                for(int l = k + 1; l < n; l++)
                    d += s[l];

                if(valid(a) && valid(b) && valid(c) && valid(d))
                {
                    string here;
                    here = a + "." + b + "." + c + "." + d;
                    ans.push_back(here);
                }
            }
        }
    }
    return ans;
}