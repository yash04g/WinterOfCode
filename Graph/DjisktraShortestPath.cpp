// Single Source shortest path for weighted graphs with no negative weight cycle
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
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
const int N = 3e5+5;
int n,e;
vpii adjList[N];
int dist[N];

int djisktra(int src){
	loop(i,0,n+1){
        dist[i] = inf;
    }
    dist[src] = 0;
    set<pii> pq;
    pq.insert(mp(0,src));
    while(!pq.empty()){
    	auto v = (*pq.begin());
    	int node = v.ss;
    	int nodeDist = v.ff;
    	pq.erase(pq.begin());
    	for(auto x:adjList[node]){
    		if(dist[x.ff]>nodeDist+x.ss){
    			auto it = pq.find(mp(dist[x.ff],x.ff));
    			if(it!=pq.end()){
    				pq.erase(it);
    			}
    			dist[x.ff] = nodeDist+x.ss;
    			pq.insert(mp(dist[x.ff],x.ff));
    		}
    	}
    }
    loop(i,1,n+1){
    	deb(i,dist[i]);
    }
}
// 4 5
// 1 2 1
// 1 3 4
// 2 3 1
// 3 4 2
// 1 4 7

int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		cin>>n>>e;
		loop(i,0,e){
			int u,v,w;
			cin>>u>>v>>w;
			adjList[u].pb(mp(v,w));
			adjList[v].pb(mp(u,w));
		}        
		int dist = djisktra(1);
    }
}
