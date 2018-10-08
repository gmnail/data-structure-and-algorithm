

struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* middleNode(struct ListNode* head)
{
	if(head == NULL)
		return head;

	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while(fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	while(fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}














