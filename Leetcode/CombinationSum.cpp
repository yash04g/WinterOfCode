// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    int n;    
    void solve(vector<int> &a,int target){
        if(target<0) return;
        if(target==0){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<n;i++){
            if(a[i]>target) break;
            int last = res.size()-1;
            if(last>=0 && a[i]<res[last]) continue; // to prevent generating a permutation of a previously generated combination
            res.push_back(a[i]);
            solve(a,target-a[i]);
            res.pop_back(); // Backtrack
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(candidates,target);
        return ans;
    }
};