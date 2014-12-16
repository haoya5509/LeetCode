/**
Remove Duplicates from Sorted List II Total Accepted: 27063 Total Submissions: 109008 My Submissions Question Solution 
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Hide Tags

Author:	haoya
Time:	10:33PM 2014/12/16
*/

ListNode *deleteDuplicates(ListNode *head) {
	ListNode solid(-1);
	solid.next=head;
	ListNode *pre=&solid,*p=head;
	while(p){
		bool flag=false;
		while(p->next&&p->val==p->next->val){
			flag=true;
			ListNode *q=p->next;
			p->next=q->next;
			delete(q);
		}
		if(flag){
			pre->next=p->next;
			delete(p);
			p=pre->next;
		}else{
			p=p->next;
			pre=pre->next;
		}
	}
	return solid.next;
}