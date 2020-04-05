#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > ans;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
    	ans.clear();
    	cin>>n;
        if(n==1){
            cout<<1<<endl<<1<<" "<<1<<endl;
            continue;
        }
        vector<int> day;
        day.push_back(1);
        day.push_back(2);
        if(n&1){
            day.push_back(n);
            n -= 1;
        }
        ans.push_back(day);
        int i = 3;
        while(i<=n){
        	vector<int> temp;
            temp.push_back(i);
            temp.push_back(i+1);
            ans.push_back(temp);
            i += 2;
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].size()<<" ";
            for(int j=0;j<ans[i].size();j++){
                if(j==((int)(ans[i].size()-1))){
                    cout<<ans[i][j]<<endl;
                }else{
                    cout<<ans[i][j]<<" ";
                }
            }
        }
    }
}