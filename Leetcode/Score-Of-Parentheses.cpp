class Solution {
public:
    int scoreOfParentheses(string s1){
        int n = s1.size();
        stack<int> s;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s1[i]=='('){
                s.push(0);
            }else{
                if(s.top()==0){
                    s.pop();
                    s.push(1);
                }else{
                    int sum = 0;
                    while(!s.empty() && s.top()!=0){
                        sum += s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(2*sum);
                }
            }
        }
        while(!s.empty()){
            cnt += s.top();
            s.pop();
        }
        return cnt;
    }
};