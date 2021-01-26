/*
	Implement Stack to get Minimum Element in O(1) time
*/
/*
	Approach 1 - Use another stack O(n) time
	Approach 2 - Use a stack with pair<int,int> type O(1) time requires modification of class
		pair.first -> current element
		pair.second -> minimum element so far
	Approach 3 - Multiplication and Modular Trick O(1) time, requires low contstraints on input numbers
		Store numbers as num * LARGE_NUM + min_element_so_far
*/
// Approach 3

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
const int MAX_VAL = 105;
/*returns min element from stack*/
int _stack :: getMin()
{
    //Your code here
    int val = -1;
    if(!s.empty())
        val = s.top() % MAX_VAL;
    return val;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    //Your code here
    int val = -1;
    if(!s.empty())
        val = s.top() / MAX_VAL, s.pop();
    return val;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    //Your code here
    if(s.empty())
    {
        x = x * MAX_VAL + x;
    }
    else
    {
        int min_val = getMin();
        if(x < min_val)
            x = x * MAX_VAL + x;
        else
            x = x * MAX_VAL + min_val;
    }
    s.push(x);
}
