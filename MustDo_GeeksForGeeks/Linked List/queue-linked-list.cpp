/*
	Implement Queue using Linked List
*/
/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
    // Your Code
    QueueNode *ptr = new QueueNode(x);
    if(front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    // Your Code
    if(front == NULL)
        return -1;
    if(front == rear)
    {
        int val = front->data;
        QueueNode *temp = front;
        front = NULL;
        rear = NULL;
        delete temp;
        return val;
    }
    else
    {
        int val = front->data;
        QueueNode *temp = front;
        front = front->next;
        delete temp;
        return val;
    }
}