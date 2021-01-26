/*
	Check if string of brackets is a valid bracket sequence
*/
/*
	Approach 1 - Using Stack

	Push open brackets into stack
	For every Closing bracket corresponding Open Bracket must be on top of the stack.
	If not or stack is empty INVALID
	At the end if Stack is not empty INVALID
*/

void cp()
{
    string s;
    cin >> s;
    stack<char> st;
    bool ok = true;
    for(char x : s)
    {
        if(x == '{' || x == '[' || x == '(')
            st.push(x);
        else
        {
            if(!st.empty())
            {
                char rev;
                if(x == '}')
                    rev = '{';
                else if(x == ']')
                    rev = '[';
                else
                    rev = '(';
                if(st.top() == rev)
                {
                    st.pop();
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                ok = false;
                break;
            }
        }
    }
    if(!st.empty())
        ok = false;
    cout << (ok ? "balanced\n" : "not balanced\n");
}