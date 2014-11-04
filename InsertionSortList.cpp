/**
Insertion Sort List Total Accepted: 26441 Total Submissions: 104467 My Submissions Question Solution 
Sort a linked list using insertion sort.

Author: haoya5509
Time: 11:33PM 2014/11/4
*/
#include<iostream>
using namespace std;

ListNode *insertionSortList(ListNode *head) {
	if(!head) return NULL;
	ListNode solid(0),*cur=head;
	solid.next=head; head=&solid;
	while(cur->next){
		ListNode *p=head; //存前一个；
		while(p->next!=cur->next&&p->next->val<=cur->next->val)
			p=p->next;
		if(p->next==cur->next){
			cur=cur->next;
			continue;
		}
		ListNode *q=cur->next->next;
		cur->next->next=p->next;
		p->next=cur->next;
		cur->next=q;
	}
	return solid.next;
}