// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int n;
    int maxProduct(vector<int>& arr) {
        n = arr.size();
        if(n==1) return arr[0];
        int max_val = 1;
        int min_val = 1;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                max_val = max_val*arr[i];
                min_val = min(1,min_val*arr[i]);
            }else if(arr[i]==0){
                min_val = 1;
                max_val = 0;
            }else{
                int prevMax = max_val;
                max_val = min_val*arr[i];
                min_val = prevMax*arr[i];
            }
            ans = max(max_val,ans);
            if(max_val<=0){
                max_val = 1;
            }
        }
        return ans;
    }
};