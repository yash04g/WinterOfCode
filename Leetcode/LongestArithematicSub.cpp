// https://leetcode.com/problems/longest-arithmetic-sequence/
class Solution {
public:
    int longestArithSeqLength(vector<int>& a){
        int n = a.size();
        if(n==1 || n==2) return n;
        vector<unordered_map<int,int>> dp(n);
        int ans = 1;
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                int diff = a[j] - a[i];
                if(dp[i].count(diff) == 0) {
                    dp[j][diff] = 2;
                }
                else{
                    dp[j][diff] = dp[i][diff] + 1;
                }
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
        
        
    }
};