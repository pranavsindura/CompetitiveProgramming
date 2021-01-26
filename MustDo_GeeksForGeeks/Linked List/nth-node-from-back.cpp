/*
	Nth Node from the Last in Linked List
*/

/*
	Approach 1 - Find Length, Find Nth node from back O(n) time O(1) space
	Approach 2 - Two pointers such that they are n distance apart, move simultaneously till end
*/

// Approach 1
int getNthFromLast(Node *head, int n)
{
    int len = 0;
    Node *temp = head;
    while(temp)
        len++, temp = temp->next;
    //nth from back means len-n+1 from first
    int pos_from_front = len - n + 1, pos = 1;
    if(pos_from_front <= 0)
        temp = head;
    while(pos < pos_from_front)
        pos++, temp = temp->next;
    return temp->data;
}

// Approach 2
int getNthFromLast(Node *head, int n)
{
    int pos = 1;
    Node *near = head, *far = head;
    while(pos < n && far->next)
        pos++, far = far->next;
    if(pos < n)
        return -1;
    while(far->next)
        far = far->next, near = near->next;
    return near->data;
}