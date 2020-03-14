// https://leetcode.com/problems/reverse-linked-list-ii/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || head->next==NULL || m==n) return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = head;
        while(m>1){
            prev = curr;
            curr = curr->next;
            m -= 1;
            n -= 1;
        }
        nextNode = curr;
        ListNode* tail = curr;
        ListNode *temp = prev;
        while(n>0){
            // cout<<1<<endl;
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            n -= 1;
        }
        if(temp!=NULL){
            temp->next = prev;
        }else{
            head = prev;
        }
        tail->next = curr;
        return head;

    }
};