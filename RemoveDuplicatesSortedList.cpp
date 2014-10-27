/**
Remove Duplicates from Sorted List Total Accepted: 31911 Total Submissions: 91594 My Submissions Question Solution 
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Author:haoya5509
Time: 12:14AM 2014/10/28
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
    if(head==NULL) return NULL;
    ListNode *p=head,*q=p->next;
    while(q){
        if(p->val==q->val){
            p->next = q->next;
            delete(q);
            q = p->next;
        }else{
            p=q;
            q=q->next;
        }
    }
    return head;
}
};