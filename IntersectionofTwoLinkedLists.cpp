/**
Intersection of Two Linked Lists Total Accepted: 5987 Total Submissions: 22742 My Submissions Question Solution
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

Author: haoya
Time:   14:30PM 2014/12/14
*/


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning,
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }

    return p1;
}

//TLE
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return NULL;
    ListNode *res = NULL;
    ListNode *p1=headA,*p2=headB,*endA;
    while(p1->next){
        p1 = p1->next;
    }p1->next=p2;//将p2连到p1后面
    endA = p1;
    res = detectCycle(headA);
    endA = NULL;
    return res;
}
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

