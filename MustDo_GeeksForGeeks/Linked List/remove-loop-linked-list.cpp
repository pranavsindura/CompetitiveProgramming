/*
	Remove loop from Linked List
*/

/*
	Approach 1 - Hashing O(nlogn) time O(n) space
		Find Loop node, remove Loop

	Approach 2 - Floyd's Cycle Detection O(n) time O(1) space
		Fast and Slow pointer concept
		Check if cycle
		If yes:
			Move slow pointer to head and keep fast intact
			Move them at same speed, they will collide again at starting of loop node!
			Traverse and Remove
*/

//Approach 2
void removeLoop(Node *head)
{
    Node *slow = head, *fast = head;
    bool loop = false;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            loop = true;
            break;
        }
    }
    if(!loop)
        return;

    slow = head;
    while(slow != fast)
        slow = slow->next, fast = fast->next;
    while(fast->next != slow)
        fast = fast->next;
    fast->next = NULL;
}