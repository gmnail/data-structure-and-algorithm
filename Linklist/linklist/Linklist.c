#include "LinkList.h"



bool GetListElem(struct LinkList *pH, int i, ElemType *data)
{
	int j = 0;
	struct LinkList *p = pH;
	while(j < i && p != NULL) {
		j++;
		p = p->next;
	}

	if(p == NULL)
		return false;
	else {
		*data = p->data;
		return true;
	}
}

bool isPalindrome(struct LinkList *pH, int length)
{
	int i;
	ElemType dat;
	char buff1[length], buff2[length];
	
	for(i = 1; i <= length; i++) {
		GetListElem(pH, i, &dat);
		buff1[i-1] = dat;
		buff2[length-i] = dat;
	}

	i = 0;
	while(i <= length) {
		if(buff1[i] == buff2[i])
			i++;
		else
			return false;
	}
	return true;
}





