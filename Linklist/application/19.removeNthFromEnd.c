

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	if(head == NULL)
		return head;

	struct ListNode *fast = head;
	struct ListNode *slow = head;
	struct ListNode *pPre = NULL;
	int i = 0;

	while(i < n-1) {
		if(fast == NULL)
			return NULL;
		fast = fast->next;
		i++;
	}

	while(fast->next != NULL) {
		pPre = slow;
		fast = fast->next;
		slow = slow->next;
	}
	if(head == slow)
		head = slow->next;
	else
		pPre->next = slow->next;
	return head;
}


struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	struct ListNode *fast = head;

	while(n--)
		fast = fast->next;
	if(!fast)
		return head->next;

	struct ListNode *slow = head;

	while(fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;

	return head;

}