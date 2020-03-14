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
int dfsc(int u,vpii adj[],vector<bool> &vis,int n,vi &v){
    vis[u]=1;
    int tot=1;
    for(auto it:adj[u]){
        if(!vis[it.ff]){
            int x=dfsc(it.ff,adj,vis,n,v);
            tot+=x;
            x*=(n-x);
            v[it.ss]=x;
        }
    }
    return tot;
}
bool cmp(pii &p1,pii &p2){
    return p1.ss<p2.ss;
}
vi dfs(vpii adj[],int n){
    vi v(n-1);
    vector<bool> vis(n,0);
    dfsc(0,adj,vis,n,v);
    return v;
}

int32_t main(){
    get_it_done();
    int q=1;
    // cin >> q;
    while (q--){
        int n,x,y;
    cin>>n;
    vpii adj[n];
    loop(i,0,n-1){
        cin>>x>>y;
        adj[x-1].pb(mp(y-1,i));
        adj[y-1].pb(mp(x-1,i));
    }
    vi v;
    v=dfs(adj,n);
    pii vx[n-1];
    loop(i,0,n-1){
        vx[i]=mp(v[i],i);
    }
    sort(vx,vx+n-1);
    loop(i,0,n-1){
        vx[i].ff=i;
    }
    sort(vx,vx+n-1,cmp);
    for(auto xt:vx)
        cout<<xt.ff<<endl;        
    }
}
