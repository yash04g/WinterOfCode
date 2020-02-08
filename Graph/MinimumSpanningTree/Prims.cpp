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
const int N = 1e5+5;
int n,e;
vpii adjList[N];
bool visited[N];
map<int,int> parent;
int weight[N];

void prims(){
    loop(i,0,n+1){
        weight[i] = inf;
        parent[i] = -1;
    }
    weight[1] = 0;
    mset(visited,0);
    priority_queue< pii, vector <pii> , greater<pii> > pq;
    pq.push(mp(weight[1],1));
    while(!pq.empty()){
        int v = pq.top().ss;
        pq.pop();
        visited[v] = 1;
        for(auto x:adjList[v]){
            if(!visited[x.ff]){
                if(weight[x.ff]>x.ss){
                    weight[x.ff] = x.ss;
                    parent[x.ff] = v;
                    pq.push(mp(x.ss,x.ff));
                }
            }
        }
    }
    // loop(i,1,n+1){
    //     int v = -1;
    //     loop(i,1,n+1){
    //         if(!visited[i] && (v==-1 || weight[i]<weight[v])){
    //             v = i;
    //         }
    //     }
    //     if(v==-1) break;
    //     for(auto neighbour:adjList[v]){
    //         if(!visited[neighbour.ff]){
    //             if(weight[neighbour.ff]>neighbour.ss){
    //                 weight[neighbour.ff] = min(weight[neighbour.ff],neighbour.ss);
    //                 parent[neighbour.ff] = v;
    //             }
    //         }
    //     }
    //     visited[v] = 1;
    // }
    loop(i,1,n+1){
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
    }

}

int32_t main(){
// 7
// 8
// 1 4 4
// 1 2 6
// 2 3 5
// 4 3 8
// 4 5 2
// 5 6 4
// 6 7 1
// 5 7 3
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
        prims();
    }
}
