// https://leetcode.com/problems/dungeon-game
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a){
        int m = a.size();
        int n = a[0].size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = INT_MAX;
            }
        }
        dp[m][n] = 1;
        dp[m-1][n] = 1;
        dp[m][n-1] = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int healthNeeded = min(dp[i+1][j],dp[i][j+1])-a[i][j];
                if(healthNeeded<=0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = healthNeeded;
                }
            }
        }
        return dp[0][0];
    }
};