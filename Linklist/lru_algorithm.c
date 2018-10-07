/*
 *	以单链表实现LRU淘汰算法
 */

#define LRU_LENGTH	100

struct ListNode {
	struct ListNode *next;
	int val;
};

struct ListNode *delete(struct ListNode *pHead, int value)
{
	struct ListNode *p = pHead->next;
	struct ListNode *pre = pHead;

	while(p != NULL) {
		if(p->val == value) {
			pre->next = p->next;
			free(p);
			return p;
		}
		pre = p;
		p = p->next;
	}

	return NULL;
}

struct ListNode insert(struct ListNode *pHead, int value)
{
	struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode))
	if(!p)
		return NULL;
	
	p->val = value;
	
	p->next = pHead->next;
	pHead->next = p;
	
	return p;
}

/*
 *	两种情况：
 *	1.需要访问的新数据已经在链表中了———将这个数据对应的结点删除并插入链表头
 *	2.需要访问的新数据还不在链表中———1* 链表已满：删除末尾的数据，并将新数据插入头部
 *									 2* 链表未满：直接插入头部
 */

bool linklist_Isfull(struct ListNode *pHead)
{
	struct ListNode *p = pHead;
	int count = 0;
	while(p->next != NULL) {
		count++;
		p = p->next;
	}
	if(count == LRU_LENGTH)
		return true;

	return false;
}

void lru_algorithm(struct ListNode *pHead, int value)
{
	struct ListNode *p = pHead;
	struct ListNode *pre = NULL;
	
	while(p->next != NULL) {
		pre = p;
		p = p->next;
		//需要访问的新数据已经在链表中了
		if(p->val == value) {
			pre->next = p->next;
			insert(pHead, value);
			return;
		}
	}
	//需要访问的新数据还不在链表中
	//链表已满,此时p已经指向了链表的末尾
	if(linklist_Isfull(pHead)) {
		pre->next = NULL;
	}
	insert(pHead, p->val);
}




















