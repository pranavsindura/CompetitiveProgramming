/*
	REVERSE A LINKED LIST
*/

/*
	Approach 1 - Make new list O(n) time O(n) space
	Approach 2 - Use three pointers O(n) time O(1) space
	Break ties and reverse them sequentially
*/

// Should reverse list and return new head.
Node* reverseList(Node *head)
{
  Node *prev = NULL, *curr = head, *next;
  while(curr != NULL)
  {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
  }
  return prev;
}