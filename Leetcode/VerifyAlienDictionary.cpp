// https://leetcode.com/problems/verifying-an-alien-dictionary/submissions/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        int n = order.length();
        for(int i=0;i<n;i++) m[order[i]]=i;
        n = words.size();
        
        for(int i=0;i<n-1;i++){
            int j = 0;
            int n1 = min(words[i+1].length(),words[i].length());
            // cout<<n1<<endl;
            while(j<n1){
                // cout<<words[i][j]<<" "<<m[words[i][j]]<<endl;
                // cout<<words[i+1][j]<<" "<<m[words[i+1][j]]<<endl;
                if(m[words[i][j]]>m[words[i+1][j]]) return 0;
                else if(m[words[i][j]]==m[words[i+1][j]]){
                    j += 1;
                }else{
                    break;
                }
            }
            if(j==n1){
                if(words[i].length()>words[i+1].length()){
                    return 0;
                }
            }
        }
        return 1;
    }
};