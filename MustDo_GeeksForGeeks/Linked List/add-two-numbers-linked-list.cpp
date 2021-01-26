/*
	Add Two Numbers represented by Linked List
*/

/*
	Approach 1 - Similar to array, iterative
	Approach 2 - Recursive
*/
// Approach 1
Node *addTwoLists(Node *first, Node *second)
{
    Node *head = NULL, *ptr = NULL;
    int carry = 0;
    while(first && second)
    {
        int sum = first->data + second->data + carry;
        Node *p = new Node(sum % 10);
        carry = sum / 10;
        if(head == NULL)
        {
            head = p;
            ptr = p;
        }
        else
        {
            ptr->next = p;
            ptr = p;
        }
        first = first->next;
        second = second->next;
    }
    while(first)
    {
        int sum = first->data + carry;
        Node *p = new Node(sum % 10);
        carry = sum / 10;
        if(head == NULL)
        {
            head = p;
            ptr = p;
        }
        else
        {
            ptr->next = p;
            ptr = p;
        }
        first = first->next;
    }
    while(second)
    {
        int sum = second->data + carry;
        Node *p = new Node(sum % 10);
        carry = sum / 10;
        if(head == NULL)
        {
            head = p;
            ptr = p;
        }
        else
        {
            ptr->next = p;
            ptr = p;
        }
        second = second->next;
    }
    if(carry)
    {
        Node *p = new Node(carry);
        if(head == NULL)
        {
            head = p;
            ptr = p;
        }
        else
        {
            ptr->next = p;
            ptr = p;
        }
    }
    return head;
}

//Approach 2
int carry = 0;
Node *addTwoLists(Node *first, Node *second)
{
    if(!first && !second && !carry)
        return NULL;
    int a = 0, b = 0;
    if(first)
        a = first->data;
    if(second)
        b = second->data;
    int sum = a + b + carry;
    carry = sum / 10;
    Node *head = new Node(sum % 10);
    if(first && second)
        head->next = addTwoLists(first->next, second->next);
    else if(first)
        head->next = addTwoLists(first->next, second);
    else if(second)
        head->next = addTwoLists(first, second->next);
    else if(carry)
        head->next = addTwoLists(first, second);
    return head;
}