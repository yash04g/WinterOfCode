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
const int N = 3e5+5;
int arr[N];
int dp[N];
vi adjList[N];

void dfs(int node,int par){
    dp[node] = arr[node];
    int maxi = 0;
    for(auto x:adjList[node]){
        if(x!=par){
            dfs(x,node);
            maxi = max(maxi,dp[x]);
        }
    }
    dp[node] += maxi;
}

void solve(){
    int n;
    cin>>n;
    loop(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    loop(i,1,n+1) cin>>arr[i];
    mset(dp,0);
    dfs(1,-1);
    cout<<dp[1]<<endl;
}

int32_t main(){
    get_it_done();
    int tc=1;
    // cin >> tc;
    while (tc--){
    // 14
    // 1 2
    // 1 3
    // 1 4
    // 2 5
    // 2 6
    // 5 11
    // 5 12
    // 3 7
    // 7 13
    // 7 14
    // 4 8
    // 4 9
    // 4 10
    // 3 2 1 10 1 3 9 1 5 3 4 5 9 8
        solve();        
    }
}
