

struct ListNode {
	struct ListNode *next;
	int data;
};

//头指针
struct ListNode *listReverse(struct ListNode *head)
{
	if(head == NULL || head->next == NULL)
		return head;
	
	struct ListNode *p = head;
	struct ListNode *pBack = NULL;

	while(p->next != NULL) {
		pBack = p->next;

		if(p == head)
			p->next = NULL;
		else
			p->next = head;

		head = p;
		p = pBack;
	}
	p->next = head;
	head = p;

	return head;
}














