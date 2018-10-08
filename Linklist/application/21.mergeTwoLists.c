
struct ListNode {
	int val;
	struct ListNode *next;
};
/*
struct ListNode* insertTail(struct ListNode *pHead, int value)
{
	struct ListNode *pNew = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(!pNew)
		return;
	pNew->val = value;
	pNew->next = NULL;
	if(pHead == NULL) {
		pHead = pNew;
		return pHead;
	}
	
	struct ListNode *p = pHead;
	while(p->next != NULL) {
		p = p->next;
	}
	p->next = pNew;
	
	return pHead;
}
*/
struct ListNode mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* res;

	if(!l2)
		return l1;
	else if(!l1)
		return l2;
	else if(l1->val <= l2->val) {
		res = l1;
		res->next = mergeTwoLists(l1->next,l2);
	}
	else if(l1->val > l2->val) {
		res = l2;
		res->next = mergeTwoLists(l1, l2->next);
	}

	return res;
}


struct ListNode *newNode(int data)
{
	struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
	p->val = data;
	p->next = NULL;

	return p;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL && l2 == NULL)
        return;
    
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    
    struct ListNode *aCurrent = l1;
	struct ListNode *bCurrent = l2;
	
	struct ListNode *res = NULL;
	struct ListNode *temp = NULL;
	
	while(aCurrent != NULL && bCurrent != NULL)
	{
		if(aCurrent->val <= bCurrent->val)
		{
			struct ListNode *n = newNode(aCurrent->val);
			if(res == NULL)
			{
				res = n;
				temp = res;
			}
			else
			{
				temp->next = n;
				temp = temp->next; 
			}
			aCurrent = aCurrent->next;
		}
		else
		{
			struct ListNode *n = newNode(bCurrent->val);
			if(res == NULL)
			{
				res = n;
				temp = res;	
			}
			else
			{
				temp->next = n;
				temp = temp->next;
			}
			bCurrent = bCurrent->next;
		}
	}
	
	while(aCurrent != NULL)
	{
		struct ListNode *n = newNode(aCurrent->val);
		temp->next = n;
		temp = temp->next;
		aCurrent = aCurrent->next;
	}
	
	while(bCurrent != NULL)
	{
		struct ListNode *n = newNode(bCurrent->val);
		temp->next = n;
		temp = temp->next;
		bCurrent = bCurrent->next;
	}
	
	return res;
}




















