// https://codeforces.com/contest/1144/problem/F
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
const int N = 1e5+5;
int dp[N];
vi adjList[200005];
vi color(200005,-1);
vector<bool> visited(200005,0);
bool isBipartite(int src,int clr){
	visited[src] = true;
	color[src] = clr;
	for(int neighbour : adjList[src]){
		if(visited[neighbour]){
			if(color[neighbour]==clr){
				return false;
			}
		}else{
			bool check = isBipartite(neighbour,clr^1);
			if(check==false)
				return false;
		}
	}
	return true;

}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n,m;
		cin>>n>>m;
		vpii a;
		fo(i,m){
			int u,v;
			cin>>u>>v;
			adjList[u].pb(v);
			adjList[v].pb(u);
			a.pb(mp(u,v));
		}
		if(!isBipartite(1,1)){
			cout<<"No"<<endl;
			continue;
		}else{
			cout<<"Yes"<<endl;
			for(int i=0;i<m;i++){
				cout<<color[a[i].first];
			}
		}	
    }
}
