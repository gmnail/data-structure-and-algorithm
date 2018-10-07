

struct ListNode {
	struct ListNode *next;
	int val;
};

//找到回文字符串的中点，并将前一段链表逆序，与后一段对比
bool link_Palindrome(struct ListNode *pHead)
{
	if(pHead == NULL || pHead->next == NULL)
		return true;

	struct ListNode *fast_ptr = pHead;
	struct ListNode *slow_ptr = pHead;
	struct ListNode *pre = NULL;

	while(fast_ptr!= NULL && fast_ptr->next != NULL) {
		fast_ptr = fast_ptr->next->next;
		struct ListNode *pNext = slow_ptr->next;
		pre = slow_ptr;
		slow_ptr->next = pre;
		pre =slow_ptr;
		slow_ptr = pNext;
	}

	if(fast_ptr != NULL)
		slow_ptr = slow_ptr->next;

	while(slow_ptr != NULL) {
		if(slow_ptr->val != pre->val)
			return false;
		slow_ptr = slow_ptr->next;
		pre = pre->next;
	}
	return true;
}











