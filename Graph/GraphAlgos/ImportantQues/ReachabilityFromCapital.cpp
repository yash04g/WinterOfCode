// https://codeforces.com/contest/999/problem/E
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
const int N = 5005;
int n,m,s;
vi adjList[N];
bool good[N],visited[N];
int cnt = 0;
 
void dfs1(int src){
    good[src] = 1;
    for(auto x:adjList[src]){
        if(!good[x]){
            dfs1(x);
        }
    }
}
 
void dfs2(int src){
    visited[src] = 1;
    cnt++;
    for(auto x:adjList[src]){
        if(!visited[x] && !good[x]){
            dfs2(x);
        }
    }
}
 
int32_t main(){
    get_it_done();
    int tc=1;
    // cin >> tc;
    while (tc--){
        cin>>n>>m>>s;
        loop(i,0,m){
            int u,v;
            cin>>u>>v;
            adjList[u].pb(v);
        }        
        dfs1(s);
        vpii bad;
        loop(i,1,n+1){
            if(!good[i]){
                mset(visited,0);
                cnt = 0;
                dfs2(i);
                bad.pb(mp(cnt,i));
            }
        }
        sort(all(bad),greater<pii>());
        int ans = 0;
        loop(i,0,bad.size()){
            auto x = bad[i];
            if(!good[x.ss]){
                ans++;
                dfs1(x.ss);
            }
        }
        cout<<ans<<endl;
    }
}