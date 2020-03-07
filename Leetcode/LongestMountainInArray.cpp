// https://leetcode.com/problems/longest-mountain-in-array/
class Solution {
public:
    int n;
    int longestMountain(vector<int>& a) {
        n = a.size();
        if(n<=2) return 0;
        int ans = 0;
        int start = 0;
        while(start<n){
            int end = start;
            if(end+1<n && a[end]<a[end+1]){
                // Setting end to the peak
                while(end+1<n && a[end]<a[end+1])
                    end++;
                // End is really a peak
                if(end+1<n && a[end]>a[end+1]){
                    while(end+1<n && a[end]>a[end+1])
                        end++;
                    ans = max(ans,end-start+1);
                }
            }
            start = max(end,start+1);
        }
        return ans;
        
    }
};