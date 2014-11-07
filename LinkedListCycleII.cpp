#include<iostream>
using namespace std;
ListNode *detectCycle(ListNode *head) {
	if(!head) return NULL;
	if(!hasCycle(head))
		return NULL;
	ListNode *p=head,*q=head;
	
}
bool hasCycle(ListNode *head){
	if(!head) return false;
	ListNode *p=head,*q=head;
	while(p->next && q->next){
		p=p->next;
		if(q->next->next)
			q=q->next->next;
		else
			return false;
		if(p==q)
			return true;
	}
	return false;
}
