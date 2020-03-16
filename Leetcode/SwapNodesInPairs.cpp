// https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swap(ListNode* next1, ListNode* next2) {
        next1->next = next2->next;
        next2->next = next1;
        return next2;
    }
    ListNode* swapPairs(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *cur = dummy;
        while (cur->next != NULL && cur->next->next != NULL) {
            cur->next = swap(cur->next, cur->next->next);
            cur = cur->next->next;
        }
        return dummy->next;
    }
};