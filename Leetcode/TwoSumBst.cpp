// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> a;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int n = a.size();
        if(n<=1) return 0;
        int i=0;
        int j=n-1;
        while(i<j){
            if(a[i]+a[j]==k){
                return 1;
            }else if(a[i]+a[j]<k){
                i++;
            }else{
                j--;
            }
        }
        return 0;
    }
};