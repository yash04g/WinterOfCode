// https://leetcode.com/problems/3sum-closest
class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        int n = a.size();
        if(n<3) return 0;
        int minDiff = INT_MAX, Diff, result;
        sort(a.begin(),a.end());
        for(int i=0;i<n;++i){
            int lo=i+1,hi=n-1, goal = target - a[i], sum;
            while(lo<hi){
                sum = a[lo] + a[hi];
                Diff = abs(sum-goal);
                if(Diff< minDiff){
                    minDiff = Diff;
                    result = a[lo]+a[i]+a[hi];
                }    
                if(sum < goal){
                    lo++;
                }else if(sum > goal){
                    hi--;
                }else{
                    break;
                }
            }
        }
        return result;
    }
};