// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
class Solution {
public:
    int dp[305][305];
    
    int getSum(int i,int j){
        if(i<0 || j<0) return 0;
        return dp[i][j];
    }
    
    bool possible(int len,int r,int c,int val){
        for(int i=len-1;i<r;i++){
            for(int j=len-1;j<c;j++){
                int sum = getSum(i,j)-getSum(i-len,j)-getSum(i,j-len)+getSum(i-len,j-len);
                if(sum<=val){
                    return true;
                }
            }
        }
        return false;
    }    
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        memset(dp,0,sizeof(dp));
        int r = mat.size();
        int c = mat[0].size();
        if(r==0 || c==0) return 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dp[i][j] = getSum(i-1,j)+getSum(i,j-1)-getSum(i-1,j-1)+mat[i][j];
            }
        }          
        int low = 1;
        int high = min(r,c);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(mid,r,c,threshold)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};