// https://codeforces.com/problemset/problem/1217/D
#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mi map<int,int>
#define mc map<char,int>  
#define pll pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
const int N = 2e5+5;
int dp[N];
int n,m;
vpii adjList[5005];
vi colors(5005,0);
vi ans(5005,0);
bool cycle = false;

void dfs(int node){
	colors[node] = 1;
	for(auto neighbour : adjList[node]){
		if(colors[neighbour.first]==0){
			dfs(neighbour.first);
			ans[neighbour.second] = 1;
		}else if(colors[neighbour.first]==2){
			ans[neighbour.second] = 1;
		}else{
			cycle = true;
			ans[neighbour.second] = 2;
		}
	}
	colors[node] = 2;
}


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	cin>>n>>m;
    	fo(i,m){
    		int u,v;
    		cin>>u>>v;
    		adjList[u].pb(mp(v,i));
    	}
    	Fo(i,1,n+1){
    		if(colors[i]==0){
    			dfs(i);
    		}
    	}
    	if(cycle){
    		cout<<2<<endl;
    	}else{
    		cout<<1<<endl;
    	}
    	fo(i,m)
    		cout<<ans[i]<<" ";
    }
}
