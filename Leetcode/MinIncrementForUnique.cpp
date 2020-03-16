// https://leetcode.com/problems/minimum-increment-to-make-array-unique
class Solution {
public:
    int n;
    int minIncrementForUnique(vector<int>& a) {
        n = a.size();
        if(n==0 || n==1) return 0;
        int dp[100005];
        int ans = 0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[a[i]]++;
        }
        for(int i=0;i<100005;i++){
            if(dp[i]>=2){
                ans += (dp[i]-1);
                dp[i+1] += (dp[i]-1);
            }
        }
        return ans;
        
        
    }
};