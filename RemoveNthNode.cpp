/**
Remove Nth Node From End of List Total Accepted: 25585 Total Submissions: 86992 My Submissions Question Solution 
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Author: haoya5509  
Time: 11:44PM 2014/10/27
*/

#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(0){}
};
ListNode *removeNthFromEnd(ListNode *head, int n) {
    if(head==NULL) return head;
    ListNode fakeListNode(0);
    fakeListNode.next = head;
    head = &fakeListNode;
    ListNode *p,*q;
    p=q=head;
    for(int i=0;i<n;i++){
        if(q==NULL) return head->next;
        q=q->next;
    }
    while(q->next){
        p=p->next;
        q=q->next;
    }
    p->next = p->next->next;
    return head->next;
}