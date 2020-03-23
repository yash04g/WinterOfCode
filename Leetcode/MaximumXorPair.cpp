// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array
class TrieNode{
public:
    TrieNode *left;
    TrieNode *right;
};
class Solution {
public:
    int n;
    void insert(TrieNode *head,int num){
        TrieNode *curr = head;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(bit==0){
                if(curr->left==NULL){
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }else{
                if(curr->right==NULL){
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        n = nums.size();
        TrieNode *head = new TrieNode();
        for(int i=0;i<n;i++){
            insert(head,nums[i]);
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            int val = nums[i];
            int c = 0;
            TrieNode *curr = head;
            for(int j=31;j>=0;j--){
                int bit = (val>>j)&1;
                if(bit==0){
                    if(curr->right){
                        c += (1<<j);
                        curr = curr->right;
                    }else{
                        curr = curr->left;
                    }
                }else{
                    if(curr->left){
                        c += (1<<j);
                        curr = curr->left;
                    }else{
                        curr = curr->right;
                    }
                }
            }
            maxi = max(maxi,c);
        }
        return maxi;
    }
};