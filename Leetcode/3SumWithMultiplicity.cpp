// https://leetcode.com/problems/3sum-with-multiplicity/solution/
class Solution {
public:
    const int mod = 1e9+7;
    int threeSumMulti(vector<int>& a, int target){
        int n = a.size();
        if(n<3) return 0;
        int ans = 0;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                if(a[i]+a[j]+a[k]>target){
                    k--;
                }else if(a[i]+a[j]+a[k]<target){
                    j++;
                }else if(a[j]!=a[k]){
                    int left = 1,right = 1;
                    while(j+1<k && a[j]==a[j+1]){
                        left += 1;
                        j += 1;
                    }
                    while(k-1>j && a[k]==a[k-1]){
                        right += 1;
                        k -= 1;
                    }
                    ans = (ans + (left*right)%mod)%mod;
                    j++;
                    k--;
                }else{
                    ans = (ans + ((k-j+1)*(k-j)/2)%mod)%mod;
                    break;
                }
            }
        }
        return ans;
        
    }
};