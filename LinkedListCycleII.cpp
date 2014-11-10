/**
Linked List Cycle II Total Accepted: 27777 Total Submissions: 90267 My Submissions Question Solution 
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

Author: haoya5509
Time: 18:31pm 2014/11/10
*/
#include<iostream>
using namespace std;
ListNode *detectCycle(ListNode *head) {
	if(!head) return NULL;
	if(!hasCycle(head))
		return NULL;
	ListNode *p=head,*q=head->next;
	while(p!=q){
		p=p->next;
		q=q->next->next;
	}
	ListNode *t=head;
	while(true){
		p=p->next;
		if(p==t) return t;	//!!!self-circle
		while(p!=q){
			if(p==t) return t;
			p=p->next;
		}
		t=t->next;
	}
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