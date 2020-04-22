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
int n,m,a,b,c;
vi bfs(int src){
    vi dist(n+1);
    vi visited(n+1,0);
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x:adjList[node]){
            if(!visited[x]){
                visited[x] = 1;
                dist[x] = 1+dist[node];
                q.push(x);
            }
        }
    }
    return dist;
}

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        cin>>n>>m>>a>>b>>c;
        loop(i,1,n+1) adjList[i].clear();
        vi prices(m+1);
        loop(i,1,m+1) cin>>prices[i];
        sort(all(prices));
        loop(i,0,m){
            int u,v;
            cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        vi dist1 = bfs(a);
        vi dist2 = bfs(b);
        vi dist3 = bfs(c);
        loop(i,1,m+1){
            prices[i] += prices[i-1];
        }
        int ans = inf;
        loop(i,1,n+1){
            if(dist1[i]+dist2[i]+dist3[i]>m){
                continue;
            }
            ans = min(ans,prices[dist2[i]]+prices[dist1[i]+dist2[i]+dist3[i]]);
        }
        cout<<ans<<endl;


    }
}
