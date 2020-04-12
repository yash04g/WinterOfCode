#include<bits/stdc++.h>
using namespace std;
int n;

void print(vector<vector<int> > &arr){
    n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i].size()<<" ";
        for(int j=0;j<arr[i].size();j++){
            if(j==((int)(arr[i].size()-1))){
                cout<<arr[i][j]<<endl;
            }else{
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n;
        if(n==1){
            cout<<1<<endl<<1<<" "<<1<<endl;
            continue;
        }
        vector<vector<int> > ans;
        vector<int> days;
        days.push_back(1);
        days.push_back(2);
        if(n%2==1){
            days.push_back(n);
            n -= 1;
        }
        ans.push_back(days);
        for(int i=3;i<=n;i+=2){
            vector<int> days;
            days.push_back(i);
            days.push_back(i+1);
            ans.push_back(days);
        }
        cout<<ans.size()<<endl;
        print(ans);
    }
    return 0;
}
