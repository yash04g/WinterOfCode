#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(auto i=(a);i<=(b);i++)
#define elif else if
#define FORA(x,arr) for(auto &x:arr)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define fio freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define UL unsigned long
#define mp(a,b) make_pair(a,b)
#define pi pair<int,int>
#define mms(a) memset(a,0,sizeof(a))
using namespace std;
int dfsc(int u,vector<pair<int,int> > adj[],vector<bool> &vis,int n,vector<int> &v){
	vis[u]=1;
	int tot=1;
	for(auto it:adj[u]){
		if(!vis[it.first]){
			int x=dfsc(it.first,adj,vis,n,v);
			tot+=x;
			x*=(n-x);
			v[it.second]=x;
		}
	}
	return tot;
}
bool cmp(pi &p1,pi &p2){
	return p1.second<p2.second;
}
vector<int> dfs(vector<pi> adj[],int n){
	vector<int> v(n-1);
	vector<bool> vis(n,0);
	dfsc(0,adj,vis,n,v);
	return v;
}
int main(){
	fastio
	// #ifndef ONLINE_JUDGE
	// fio
	// #endif
	int n,x,y;
	cin>>n;
	vector<pair<int,int> > adj[n];
	FOR(i,0,n-2){
		cin>>x>>y;
		adj[x-1].pb(mp(y-1,i));
		adj[y-1].pb(mp(x-1,i));
	}
	vector<int> v;
	v=dfs(adj,n);
	pi vx[n-1];
	FOR(i,0,n-2){
		vx[i]=mp(v[i],i);
	}
	sort(vx,vx+n-1);
	FOR(i,0,n-2){
		vx[i].first=i;
	}
	sort(vx,vx+n-1,cmp);
	FORA(xt,vx)
		cout<<xt.first<<endl;
}