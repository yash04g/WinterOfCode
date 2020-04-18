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
const int N = 2e5+5;
vi adjList[N];
int n,k;
int sub[N];
int dist[N];
bool visited[N];

int dfs(int src,int par,int lvl){
    int curr_size = 1;
    dist[src] = lvl;
    for(auto x:adjList[src]){
        if(x!=par){
            curr_size += dfs(x,src,lvl+1);
        }
    }
    sub[src] = curr_size;
    return curr_size;
}


int32_t main(){
    get_it_done();
    int q=1;
    // cin >> q;
    while (q--){
        cin>>n>>k;        
        loop(i,1,n){
            int u,v;
            cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        mset(dist,0);
        mset(sub,0);
        dfs(1,-1,0);
        priority_queue<int> pq;
        loop(i,1,n+1){
            // cout<<dist[i]<<" "<<sub[i]<<endl;
            pq.push(dist[i]-(sub[i]-1));
        }
        int ans = 0;
        loop(i,0,k){
            ans += pq.top();
            pq.pop();
        }
        cout<<ans<<endl;
        


    }
}
