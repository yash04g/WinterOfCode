// https://leetcode.com/problems/next-greater-node-in-linked-list/
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
    vector<int> nextLargerNodes(ListNode* head) {
        
        if(head==NULL){
            vector<int> ans;
            return ans;
        }
        if(head->next==NULL){
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }
        vector<int> a;
        ListNode *temp = head;
        while(temp!=NULL){
            a.push_back(temp->val);
            // cout<<temp->val<<" ";
            temp = temp->next;
            
        }
        // cout<<endl;
        int n = a.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && a[i] >= s.top())
                s.pop();
            if(s.empty()) 
                ans[i] = 0;
            else 
                ans[i] = s.top();
            s.push(a[i]);
        }
        return ans;
    }
};