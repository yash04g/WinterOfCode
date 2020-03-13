// https://leetcode.com/problems/top-k-frequent-words/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        priority_queue<pair<int,string>> pq;
        priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>> pq2;
        map<string,int> m;
        vector<string> ans;
        for(int i=0;i<n;i++){
            m[words[i]]++;
        }
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(pq2.empty()){
                pq2.push({x.second,x.first});
            }else{
                auto y = pq2.top();
                if(y.second==x.first){
                    pq2.push({x.second,x.first});
                }else{
                    while(!pq2.empty()){
                        ans.push_back(pq2.top().first);
                        pq2.pop();
                    }
                    pq2.push({x.second,x.first});
                }
            }
        }
        while(!pq2.empty()){
            ans.push_back(pq2.top().first);
            pq2.pop();
        }
        vector<string> res;
        for(int i=0;i<k;i++){
            res.push_back(ans[i]);
        }
        return res;
        
            
            
    }
};