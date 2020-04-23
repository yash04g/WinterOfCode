#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mset(a,i) memset(a,i,sizeof(a))
#define mii map<int,int>  
#define pii pair<int,int>
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { if(0) return; cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){   
    if(0) return; 
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
void get_it_done(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int gcd(int a,int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}
const int N = 1e5+5;
int n,m;
vi adjList[N];
vi tg[N];
vi ans;
bool visited[N];
stack<int> st;
void dfs(int src){
    visited[src] = 1;
    for(auto x:adjList[src]){
        if(!visited[x]) dfs(x);
    }
    st.push(src);
}

void dfs1(int node){
    visited[node] = 1;
    ans.pb(node);
    for(auto x:tg[node]){
        if(!visited[x]) dfs1(x);
    }
}

int32_t main(){
// 1
// 5 5 
// 2 1
// 3 2
// 1 3
// 1 4
// 4 5
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        while(!st.empty()) st.pop();
        cin>>n>>m;
        loop(i,0,n+1) adjList[i].clear(),tg[i].clear();
        loop(i,0,m){
            int u,v;
            cin>>u>>v;
            adjList[u].pb(v);
        }
        memset(visited,0,sizeof(visited));
        loop(i,1,n+1){
            if(!visited[i]){
                dfs(i);
            }
        }
        loop(i,1,n+1){
            for(auto x:adjList[i]){
                tg[x].pb(i);
            }
        }   
        memset(visited,0,sizeof(visited));
        vvi scc;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                ans.clear();
                dfs1(node);
                scc.pb(ans);
            }
        }
        loop(i,0,scc.size()){
            loop(j,0,scc[i].size()){
                cout<<scc[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
    }
}
