#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define vvi vector<vector<int> >
#define pb push_back
#define endl "\n"
#define inf 1e9
const int N = 1e5+5;
const int mod = 1e9+7;
vector<int> adjList[N];
map<int,int> m[N];
int n,q;
bool visited[N];
vector<int> ans;
bool dfs(int src,int dest){
    visited[src]=1;
    if(src==dest){
        ans.pb(dest);
        return 1;
    }
    bool flag;
    for(auto x:adjList[src]){
        if(!visited[x]){
            flag=dfs(x,dest);
            if(flag){
                ans.pb(src);
                return 1;
            }
        }
    }
    return 0;
}

void factorize(vector<int> &arr){
    loop(i,1,n+1){
        int temp = arr[i];
        for(int j=2;j*j<=temp;j++){
            while(temp%j==0){
                m[i][j]+=1;
                temp /= j;
            }
        }
        if(temp>1) m[i][temp] += 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        cin>>n;
        loop(i,0,n+1){
            adjList[i].clear();
        }
        loop(i,0,n-1){
            int u,v;
            cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }        
        vector<int> vals(n+1,0);
        loop(i,1,n+1) cin>>vals[i],m[i].clear();
        factorize(vals);
        cin>>q;
        while(q--){
            ans.clear();
            memset(visited,0,sizeof(visited));
            int s,d;
            cin>>s>>d;
            if(s>n || d>n){
                cout<<0<<endl;
                continue;
            }
            dfs(s,d);
            map<int,int> m1;
            loop(i,0,ans.size()){
                for(auto x:m[ans[i]]){
                    m1[x.ff] += x.ss;
                }
            }
            int ans = 1;
            for(auto x:m1){
                ans=(ans*(x.ss+1)%mod)%mod;
            }
            cout<<ans<<endl;
            
        }

    }
}
