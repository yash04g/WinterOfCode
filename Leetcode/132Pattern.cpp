class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        n = nums.size();
        if(n<3) return 0;
        int s3 = INT_MIN;
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<s3){
                return true;
            }else{
                while(!s.empty() && nums[i]>s.top()){
                    s3 = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return 0;
    }
};