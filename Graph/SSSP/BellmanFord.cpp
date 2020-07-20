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
vvi edges;

vi bellman_ford(int src,int n){
    vi dist(n+1,inf);
    dist[src] = 0;
    loop(i,0,n-1){
        // Reslaxing the edges
        for(auto x:edges){
            int u = x[0],v = x[1],w = x[2];
            if(dist[u]!=inf && dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
            }
        }
    }
    // checking for negative weight cycle
    for(auto x:edges){
        int u = x[0],v = x[1],w = x[2];
        if(dist[u]!=inf && dist[v]>dist[u]+w){
            cout<<"Negative weight cycle is present"<<endl;
            exit(0);
        }
    }

    return dist;
}

void solve(){
    int n,m;
    cin>>n>>m;
    loop(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges.pb({u,v,w});
    }
    vi ans = bellman_ford(1,n);
    loop(i,1,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int32_t main(){
    get_it_done(); 
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
