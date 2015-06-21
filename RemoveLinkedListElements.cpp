/**
Remove Linked List Elements Total Accepted: 5409 Total Submissions: 20154 My Submissions
Question  Solution

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Author: haoya
Time:   2015/4/29 8:59AM

*/
ListNode* removeElements(ListNode* head, int val) {
    ListNode guard(-1000000);
    guard.next = head;
    ListNode *iter = &guard;
    while(iter && iter->next){
        if(iter->next->val == val) {
            iter->next = iter->next->next;
        } else{
            iter = iter->next;
        }
    }
    return guard.next;
}