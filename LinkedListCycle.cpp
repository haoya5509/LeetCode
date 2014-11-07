/**
Linked List Cycle Total Accepted: 37373 Total Submissions: 104489 My Submissions Question Solution 
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Author: haoya5509
Time: 2014/11/7 15:44pm
*/

#include<iostream>
using namespace std;
//destory the link structure;
bool hasCycle(ListNode *head) {
	if(!head) return false;
	//visited node has a flag
	ListNode *flag = new ListNode(0);
	ListNode *p=head,*q=head;
	while(p){
		if(p==flag) {
			delete flag;
			return true;
		}
		q=p;
		p=p->next;
		q->next=flag;
	}      
	delete flag;
	return false;
}
//use two difference speed
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
