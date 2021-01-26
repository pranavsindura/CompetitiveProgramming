/*
	Sort Linked List filled with 0,1,2
*/

/*
	Approach 1 - Count and change data
	Approach 2 - Make new list of only zeros, ones and twos combine later
*/

// Approach 1
Node *segregate(Node *head)
{

    // Add code here
    int zero = 0, one = 0, two = 0;
    Node *temp = head;
    while(temp)
    {
        if(temp->data == 0)
            zero++;
        else if(temp->data == 1)
            one++;
        else
            two++;
        temp = temp->next;
    }
    temp = head;
    while(zero && temp)
        temp->data = 0, temp = temp->next, zero--;
    while(one && temp)
        temp->data = 1, temp = temp->next, one--;
    while(two && temp)
        temp->data = 2, temp = temp->next, two--;
    return head;
}