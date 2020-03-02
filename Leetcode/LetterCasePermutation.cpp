// https://leetcode.com/problems/letter-case-permutation
class Solution {

public:
    vector<string> permutes;
    
    void createPermute(string& S, int i) {
        if (i == S.length()) {
            permutes.push_back(S);
            return;
        }
        createPermute(S,i+1);
        if (S[i] >= 'a' && S[i] <= 'z') {
            S[i] = char(S[i]-32);
            createPermute(S,i+1);
        }
        else if (S[i] >= 'A' && S[i] <= 'Z') {
            S[i] = char(S[i]+32);
            createPermute(S,i+1);
        }
    }
    
    vector<string> letterCasePermutation(string S){    
        createPermute(S,0);
        return permutes;
    }
    
};