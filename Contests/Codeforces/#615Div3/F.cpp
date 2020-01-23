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
#define mci map<char,int>  
#define pii pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18
#define sp(x,y) fixed<<setprecision(y)<<x

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
void swap(int &a,int &b){
    a^=b;b^=a;a^=b;
}
const int N = 2e5+5;
int dp[N];
int n;
vi adjList[N];
mii m;
// map is for storing the path of the diameter

void dfs(int node,int parent){
    if(parent!=-1){
        dp[node] = dp[parent]+1;
        m[node] = parent;
    }
    for(auto neighbour:adjList[node]){
        if(neighbour!=parent){
            dfs(neighbour,node);
        }
    }
}

int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n;
        loop(i,0,n-1){
            int x,y;
            cin>>x>>y;
            adjList[x].pb(y);
            adjList[y].pb(x);
        }
        mset(dp,0);
        dfs(1,-1);
        int node1 = -1;
        int maxi = -1;
        loop(i,1,n+1){
            if(maxi<dp[i]){
                maxi = dp[i];
                node1 = i;
            }
        }
        mset(dp,0);
        dfs(node1,-1);
        int node2 = -1;
        maxi = -1;
        loop(i,1,n+1){
            if(maxi<dp[i]){
                maxi = dp[i];
                node2 = i;
            }
        }
        queue<int> q;
        mset(dp,-1);
        int temp = node2;
        while(temp!=node1){
            q.push(temp);
            dp[temp] = 0;
            temp = m[temp];
        }
        q.push(node1);
        dp[node1] = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i : adjList[front]){
                if(dp[i]==-1){
                    q.push(i);
                    dp[i] = dp[front]+1;
                }
            }
        }
        int node3 = -1;
        int maxi1 = -1;
        loop(i,1,n+1){
            if(maxi1<dp[i] && node2!=i && node1!=i){
                maxi1 = dp[i];
                node3 = i;
            }
        }
        cout<<maxi+maxi1<<endl;
        cout<<node1<<" "<<node2<<" "<<node3<<endl;
    }
}
