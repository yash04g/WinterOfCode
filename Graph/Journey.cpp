// https://codeforces.com/problemset/problem/839/C
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
vi adjList[100005];

double dfs(int src,double prob,int len,vector<bool> &visited){
	visited[src] = true;
	double ans = 0;
	int cnt = 0;
	for(auto x : adjList[src]){
		if(!visited[x]) cnt++;
	}
	if(cnt == 0){
		return prob*((double)len);
	}
	for(auto x : adjList[src]){
		if(!visited[x]){
			ans += dfs(x,prob/cnt,len+1,visited);
		}
	}
	return ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n;
		cin>>n;
		
		fo(i,n-1){
			int u,v;
			cin>>u>>v;
			adjList[u].pb(v);
			adjList[v].pb(u);
		}
		vector<bool> visited(n+1,0);
		cout<<fixed<<setprecision(10)<<dfs(1,1.0,0,visited);

    }
}
