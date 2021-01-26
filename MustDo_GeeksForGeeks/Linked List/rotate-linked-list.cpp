/*
    ROTATE LINKED LIST BY K NODES
*/

/*
    Approach 1 - O(n)
    Find length
    break at kth node, connect
    Draw on paper, it helps
*/
Node *rotate(Node *head, int k)
{
    int len = 0;
    Node *temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    k = (len - k); // remove to move clockwise!
    k = k % len;

    if(k == 0)
        return head;

    int pos = 1;
    temp = head;
    Node *mid = head;

    while(pos < len - k)
    {
        pos++;
        temp = temp->next;
    }
    Node *new_head = temp->next;
    temp->next = NULL;
    temp = new_head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = mid;
    return new_head;
}