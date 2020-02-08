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
int parent[N],sz[N],mx[N],mn[N];
class Edge{
public:
    int src;
    int dest;
    int weight;
};
vector<Edge> adjList;
vpii ans;
int cost = 0;

void initialize(int n){
    loop(i,1,n+1) sz[i] = 1,parent[i] = i,mx[i] = i,mn[i]=i;
}
int find_parent(int a){
    if(parent[a]==a)
        return a;
    return find_parent(parent[parent[a]]);
}
bool isConnected(int a,int b){
    if(find_parent(a)==find_parent(b)) return true;
    return false;
}
int make_union(int a,int b){
    int r_a = find_parent(a);
    int r_b = find_parent(b);
    if(r_a==r_b){
        return 0;
    }
    if(sz[r_a]<sz[r_b]){
        parent[r_a] = r_b;
        sz[r_b] += sz[r_a];
        mx[r_b] = max(mx[r_a],mx[r_b]);
        mn[r_b] = min(mn[r_a],mn[r_b]);
    }else{
        parent[r_b] = r_a;
        sz[r_a] += sz[r_b];
        mx[r_a] = max(mx[r_a],mx[r_b]);
        mn[r_a] = max(mn[r_a],mn[r_b]);
    }
    return 1;
}

bool cmp(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}

void kruskal(){
    sort(all(adjList),cmp);
    int i=0;
    int cnt = 0;
    while(cnt<n-1){
        Edge e = adjList[i];
        if(!isConnected(e.src,e.dest)){
            make_union(e.src,e.dest);
            ans.pb(mp(e.src,e.dest));
            cost += e.weight;
            cnt++;
        }
        i++;
    }
}

int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n>>e;
        initialize(n);
        loop(i,0,e){
            int u,v,w;
            cin>>u>>v>>w;
            Edge e;
            e.src = u;
            e.dest = v;
            e.weight = w;
            adjList.pb(e);
        }
        kruskal();
        for(auto x:ans){
            cout<<x.ff<<" "<<x.ss<<endl;
        }
        cout<<"Cost of this path is "<<cost<<endl;
    }
}
