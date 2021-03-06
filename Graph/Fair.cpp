// https://codeforces.com/problemset/problem/987/D
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
int n,m,k,s;
vi adjList[N],goods[N],cost[N];
int arr[N],dp[105][N];
bool visited[N];

int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n>>m>>k>>s;
        loop(i,1,n+1) cin>>arr[i],goods[arr[i]].pb(i);
        loop(i,0,m){
            int u,v;
            cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        if(s==1){
            loop(i,0,n){
                cout<<0<<" ";
            }
            cout<<endl;
            continue;
        }
        loop(i,1,k+1){
            mset(visited,0);
            queue<int> q;
            for(auto x:goods[i]){
                visited[x] = 1;
                q.push(x);
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto x:adjList[node]){
                    if(!visited[x]){
                        dp[i][x] = dp[i][node]+1;
                        visited[x] = 1;
                        q.push(x);
                    }
                }
            }
            loop(j,1,n+1){
                cost[j].pb(dp[i][j]);
            }
        }
        loop(i,1,n+1){
            sort(all(cost[i]));
            int ans = 0;
            loop(j,0,s){
                ans += cost[i][j];
            }
            cout<<ans<<" ";
        }
        cout<<endl;

    }
}
