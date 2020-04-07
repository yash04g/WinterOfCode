#include <bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(int i=k;i<n;++i)
#define vi vector<int>
#define vvi vector<vector<int> >
#define all(v) v.begin(),v.end()
#define pb push_back
#define inf 1e9

vi solve(vvi &a,int n,int m,int k){
    vi ans;
    int freq[k+1];
    memset(freq,0,sizeof(freq));
    loop(i,0,n){
        map<int,int> m1;
        int mini=inf;
        loop(j,0,k){
            if(mini>freq[j]){
                mini=freq[j];
            }
        }
        loop(j,0,k){
            if(freq[j]==mini){
                m1[a[i][j]]++;    
            }
        }
        int maxi = 0;
        int val1 = 1;
        for(auto x:m1){
            if(x.second>maxi){
                maxi=x.second;
                val1=x.first;
            }
        }
        ans.pb(val1);
        loop(j,0,k){  
            if(a[i][j]==val1){
                freq[j]++;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    loop(t,0,T){
        int n,m,k;
        cin>>n>>m>>k;
        vvi a(n+1,vi(k+1,0));
        loop(i,0,n) loop(j,0,k) cin>>a[i][j];
        vi ans = solve(a,n,m,k);
        loop(i,0,n) 
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
