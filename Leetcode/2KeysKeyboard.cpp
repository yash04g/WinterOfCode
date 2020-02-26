// https://leetcode.com/problems/2-keys-keyboard/
class Solution {
public:
    
    int steps = 1e9;
    
    void helper(int n,int stp,int curr,int prev){
        if(curr>n) return;
        if(curr==n){
            steps = min(steps,stp);
            return;
        }
        helper(n,stp+1,curr+prev,prev);
        helper(n,stp+2,curr*2,curr);
    }
    
    int minSteps(int n) {
        if(n<=1) return 0;
        helper(n,1,1,1);
        return steps;
        
    }
};