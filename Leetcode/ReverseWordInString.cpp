// https://leetcode.com/problems/reverse-words-in-a-string
class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) 
            return s;
        stack<string> stack;
        string ans = "";
        int i=0;
        while(i<s.size()){
            string word;
            if(s[i]==' '){
                i++;
                continue; 
            }
            while(s[i]!=' ' && i<s.size()){
                word += s[i]; 
                i++;
            }
            stack.push(word);
        }
        while(!stack.empty()) {
            ans += stack.top(); 
            stack.pop();
            if(!stack.empty()) 
                ans += " ";
        }
        return ans;
    }
};