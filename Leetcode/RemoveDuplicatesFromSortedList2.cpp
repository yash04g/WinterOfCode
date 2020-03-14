// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        while(curr!=NULL){
            while(curr->next!=NULL && curr->next->val==prev->next->val){
                curr = curr->next;
            }
            if(prev->next==curr){
                prev = prev->next;
            }else{
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        head = dummy->next;
        return head;
    }
};