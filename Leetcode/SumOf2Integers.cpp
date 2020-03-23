// https://leetcode.com/problems/sum-of-two-integers
class Solution {
public:
    int getSum(int a, int b) {
        if(b==0) return a;
        if(a==0) return b;
        
        int sum = a^b;
        int carry = (unsigned int)(a&b)<<1;
        // cout<<sum<<" "<<carry<<endl;
        return getSum(sum,carry);
    }
};