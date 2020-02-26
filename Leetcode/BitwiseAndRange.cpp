// https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==n){
            return m&m;
        }
        if(n-m==1){
            return n&m;
        }
        if(m==0) return 0;
        int ans = 0;
        while(1){
            int cnt1 = 0;
            int cnt2 = 0;
            int m1 = m;
            int n1 = n;
            while(m1>0){
                m1 = m1/2;
                cnt1++;
            }
            while(n1>0){
                n1 = n1/2;
                cnt2++;
            }
            if(cnt1!=cnt2){
                return ans;
            }else{
                m -= 1<<(cnt1-1);
                n -= 1<<(cnt1-1);
                ans += (1<<(cnt1-1));
            }
        }
        
        
    }
};