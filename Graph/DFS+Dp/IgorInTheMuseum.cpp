// https://codeforces.com/problemset/problem/598/D
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
const int N = 1e3+5;
char input[N][N];
bool visited[N][N];
int dp[N][N];
int n,m,k;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
set<pii> s;

bool isPossible(int x,int y){
    if(x<=0 || x>n || y<=0 || y>m)
        return 0;
    return 1;
}

int dfs(int x,int y){
    if(input[x][y]=='*')
        return 1;
    if(visited[x][y])
        return 0;
    visited[x][y] = 1;
    s.insert(mp(x,y));
    int ans = 0;
    loop(i,0,4){
        int newx = x+dir[i][0];
        int newy = y+dir[i][1];
        if(isPossible(newx,newy)){
            ans += dfs(newx,newy);
        }
    }
    return ans;
}

int32_t main(){
    get_it_done();
    int q=1;
    // cin >> q;
    while (q--){
        cin>>n>>m>>k;
        loop(i,1,n+1) loop(j,1,m+1) cin>>input[i][j];
        mset(dp,-1);
        mset(visited,0);
        int ans = 0;
        while(k--){
            int x,y;
            cin>>x>>y;
            if(dp[x][y]!=-1){
                cout<<dp[x][y]<<endl;
            }else{
                s.clear();
                ans = dfs(x,y);
                cout<<ans<<endl;
                for(auto x:s){
                    dp[x.ff][x.ss] = ans;
                }
            }
        }
        
    }
}
