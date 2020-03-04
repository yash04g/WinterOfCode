// https://leetcode.com/problems/majority-element-ii
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if(n==0){
            return ans;
        }
        int cnt1=0,cnt2=0;
        int first=1e9,second=1e9;
        for(int i=0;i<n;i++){
            if(first==nums[i]){
                cnt1++;
            }else if(second==nums[i]){
                cnt2++;
            }else if(cnt1==0){
                first = nums[i];
                cnt1 = 1;
            }else if(cnt2==0){
                second = nums[i];
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==first) cnt1++;
            else if(nums[i]==second) cnt2++;
        }
        if(cnt1>(n/3)) ans.push_back(first);
        if(cnt2>(n/3)) ans.push_back(second);
        return ans;
    }
};