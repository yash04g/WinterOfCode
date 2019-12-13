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

class Graph{
public:
	int V;
	vpii *adjList;
	Graph(int v){
		V = v;
		adjList = new vpii[V];
	}
	void addEdge(int u,int v,int weight){
		adjList[u].pb(mp(v,weight));
		adjList[v].pb(mp(u,weight));
	}
	// Return size of subtree
	int dfsHelper(int node,vector<bool> &visited,vi &count,int &ans){
		visited[node] = true;
		count[node] = 1;

		//  Recursively find size of subtree
		for(auto neighbour : adjList[node]){
			int v = neighbour.first;
			if(!visited[v]){
				count[node] += dfsHelper(v,visited,count,ans);
				// Cost => Count
				int s = count[v];
				int edgeCost = neighbour.second;
				ans += 2*min(s,V-s)*edgeCost;
			}
		}
		return count[node];
	}
	int dfs(){
		vector<bool> visited(V,0);
		vi count(V,0);
		int ans = 0;
		dfsHelper(0,visited,count,ans);
		return ans;
	}	
};

int32_t main(){
	get_it_done();
	int t=1;
	cin>>t;
	fo(i,t){
		int n;
		cin>>n;
		Graph g(n);
		fo(j,n-1){
			int u,v,w;
			cin>>u>>v>>w;
			u-=1; v-=1;
			g.addEdge(u,v,w);
		}
		int ans = g.dfs();
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
}
