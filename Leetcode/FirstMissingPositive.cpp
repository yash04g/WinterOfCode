class Solution {
public:
    int n;
    void seg(vector<int> &a){
        int j=0;
        for(int i=0;i<n;i++){
            if(a[i]<=0){
                swap(a[i],a[j]);
                j++;
            }
        }
        a.erase(a.begin(),a.begin()+j);
    }
    
    int firstMissingPositive(vector<int>& nums) {
        n = nums.size();
        seg(nums);
        n = nums.size();
        // cout<<n<<endl;
        // return 0;
        for(int i=0;i<n;i++){
            if (abs(nums[i]) - 1 < n && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1]; 
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
        
    }
};