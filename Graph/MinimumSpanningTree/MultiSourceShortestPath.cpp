// Multi Source Shortest Path in Unweighted Graph
// Suppose there are n towns connected by m bidirectional roads. There are s towns among them with a police station. 
// We want to find out the distance of each town from the nearest police station. If the town itself has one the distance is 0.
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
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod; }
void get_it_done(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
const int N = 1e5+5;
int n,e,s;
int sources[N];
vi adjList[N];
int dist[N];
set<pii> q;

void multiSourceBFS(){
    int source[n+1];
    mset(source,0);
    loop(i,0,s){
        source[sources[i]] = 1;
    }
    loop(i,0,n){
        if(source[i]){
            dist[i] = 0;
            q.insert(mp(0,i));
        }else{
            dist[i] = inf;
            q.insert(mp(inf,i));
        }
    }
    while(!q.empty()){
        auto v = (*q.begin());
        for(auto x:adjList[v.ss]){
            if(dist[v.ss]+1<dist[x]){
                auto it = q.find(mp(dist[x],x));
                q.erase(it);
                dist[x] = 1+dist[v.ss];
                q.insert(mp(dist[x],x));
            }
        }
        q.erase(q.begin());
    }
    loop(i,1,n+1){
        cout<<i<<" "<<dist[i]<<endl;
    }
}

int32_t main(){
    get_it_done();
    int q=1;
    // cin >> q;
    while (q--){
        cin>>n>>e>>s;
        loop(i,0,e){
            int u,v,w;
            cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }         
        loop(i,0,s){
            cin>>sources[i];
        }
        multiSourceBFS();
        
    }
}
