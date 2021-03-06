#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long int
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds1;

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
const int N = 3e5+5;
vi adjList[N];
vpii bridges;
set<int> art;
int dis[N],low[N],timer;

void dfs(int node,int par){
    dis[node] = low[node] = timer++;
    int cnt_child = 0;
    for(auto x:adjList[node]){
        if(dis[x]==0){
            cnt_child++;
            // Child not visited
            dfs(x,node);
            low[node] = min(low[node],low[x]);
            // Check for art
            if(par!=-1 && low[x]>=dis[node]){
                art.insert(node);
            }
            // Check for bridge
            if(low[x]>dis[node]){
                bridges.pb({node,x});
            }
        }else if(x!=par){
            // Back edge
            // Cycle Found
            low[node] = min(low[node],dis[x]);
        }
    }
    if(par==-1 && cnt_child>1){
        art.insert(node);
    }
    return;
}

void solve(){
    int n,m;
    cin>>n>>m;
    loop(i,0,m){
        int u,v;
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    mset(dis,0);
    mset(low,0);
    timer = 1;
    dfs(1,-1);
    for(auto x:art) cout<<x<<" ";
    cout<<endl;
    for(auto x:bridges){
        cout<<x.ff<<" "<<x.ss<<endl;
    }
}

int32_t main(){
    get_it_done(); 
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
