// https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    int n;
    
    void solve(vector<int> &a,int target,int idx){
        if(target==0){
            if(find(ans.begin(),ans.end(),res)==ans.end()){
                ans.push_back(res);
            }
            return;
        }
        if(target<0) return;
        for(int i=idx;i<n;i++){
            res.push_back(a[i]);
            solve(a,target-a[i],i+1);
            res.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0);
        return ans;
    }
};