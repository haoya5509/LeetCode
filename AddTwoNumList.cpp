/**
Add Two Numbers Total Accepted: 27627 Total Submissions: 120938 My Submissions Question Solution 
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Author: haoya5509
Time: 10:56PM 2014/11/1
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode res(0),*p=&res;
    if(l1 == NULL && l2 == NULL) return NULL;
    if(l1 == NULL) return l1;
    if(l2 == NULL) return l2;
    int step = 0;
    while(l1&&l2){
        int val = l1->val + l2->val + step;
        ListNode *node = new ListNode(val%10);
        step = val/10;
        p->next = node;
        p = node;
        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode *q = l1 ? l1 : l2;
    while(q){
        int val = q->val + step;
        ListNode *node = new ListNode(val%10);
        step = val/10;
        p->next = node;
        p = node;
        q = q->next;
    }
    if(step){
        ListNode *node = new ListNode(1);
        p->next = node;
    }
    return res.next;
}
};