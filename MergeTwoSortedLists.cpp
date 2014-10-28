/**
Merge Two Sorted Lists Total Accepted: 29635 Total Submissions: 89169 My Submissions Question Solution 
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Author: haoya5509  
Time: 12:05Am 2014/10/29
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode head(0),*res = &head;
    while(l1 || l2){
        if(!l1 || (l2 && l1->val > l2->val)){
               res->next = new ListNode(l2->val);
               res = res->next;
            l2 = l2->next;
        }else{
                res->next = new ListNode(l1->val);
                res = res->next;
            l1 = l1->next;
        }
    }
    return head.next;
}
};