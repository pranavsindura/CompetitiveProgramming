/*
	Implement Stack using Linked List
*/

/*
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

/* The method push to push element
   into the stack */
void MyStack ::push(int x)
{
    // Your Code
    StackNode *ptr = new StackNode(x);
    if(top == NULL)
        top = ptr;
    else
        ptr->next = top, top = ptr;
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop()
{
    // Your Code
    if(top == NULL)
        return -1;
    else
    {
        int val = top->data;
        top = top->next;
        return val;
    }
}