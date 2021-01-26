/*
	FIND MIDDLE NODE IN LINKED LIST
	If even length return second of the two middle elements
*/

/*
	Approach 1 - Find length, go n/2 times. 2 traversals
	Approach 2 - Slow and fast pointer One moves +1, other moves +2
*/

//Approach 2
int getMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL)
            fast = fast->next;
    }
    return slow->data;
}