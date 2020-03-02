// https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode* slow = NULL;
    ListNode* fast = NULL;
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return 0;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return 1;
            }
        }
        return 0;
    }
    ListNode *detectCycle(ListNode *head) {
        slow = head;
        fast = head;
        bool flag = hasCycle(head);
        if(!flag) return NULL;
        fast = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
        
        
    }
};