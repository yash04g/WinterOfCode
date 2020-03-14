// https://leetcode.com/problems/add-two-numbers-ii/
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
    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
	    ListNode *tail = head->next;
	    ListNode* newHead = rev(head->next);
	    tail->next = head;
	    head->next = NULL;
	    return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        stack<int> s1;
        stack<int> s2;
        while(l1!=NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while(!s1.empty() && !s2.empty()){
            int val = s1.top()+s2.top()+carry;
            s1.pop();
            s2.pop();
            carry = val/10;
            val %= 10;
            ListNode *newNode = new ListNode(val);
            if(head==NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = tail->next;
            }            
        }
        if(!s1.empty()){
            while(!s1.empty()){
                int val = s1.top()+carry;
                carry = val/10;
                val %= 10;
                s1.pop();
                ListNode *newNode = new ListNode(val);
                tail->next = newNode;
                tail = tail->next;
            }
            if(carry>0){
                ListNode *newNode = new ListNode(carry);
                tail->next = newNode;
                tail = tail->next;
                carry = 0;
            }
        }
        else if(!s2.empty()){
            while(!s2.empty()){
                int val = s2.top()+carry;
                carry = val/10;
                val %= 10;
                s2.pop();
                ListNode *newNode = new ListNode(val);
                tail->next = newNode;
                tail = tail->next;
            }
            if(carry>0){
                ListNode *newNode = new ListNode(carry);
                tail->next = newNode;
                tail = tail->next;
                carry = 0;
            }
        }
        else if(carry>0){
                ListNode *newNode = new ListNode(carry);
                tail->next = newNode;
                tail = tail->next;
        }
        head = rev(head);
        return head;
    }
};