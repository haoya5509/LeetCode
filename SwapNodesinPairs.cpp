/**
Swap Nodes in Pairs Total Accepted: 30364 Total Submissions: 93591 My Submissions Question Solution 
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Author: haoya
Time:	12:03AM 2014/12/18
*/

ListNode *swapPairs(ListNode *head) {
	ListNode solid(0);
	solid.next=head;
	ListNode *pre=&solid,*p=head,*q;
	if(p) q=head->next;
	while(p&&q){
		ListNode *t=q->next;
		pre->next=q;
		q->next=p;
		p->next=t;
		pre=p;
		p=p->next;
		if(p) q=p->next;
	}        
	return solid.next;
}