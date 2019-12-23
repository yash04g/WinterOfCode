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
int n;
vi adjList[N];
int arr[4][N];
int ans[N];	

int cost(int node,int parent,int first,int second,int third){
    int ans=0;
    for(auto neighbour : adjList[node]){
    	if(neighbour!=parent){
    		ans += cost(neighbour,node,second,third,first);
    	}
    }
    ans += arr[first][node];
    return ans;
}

void findPath(int node,int parent,int first,int second,int third){
	ans[node] = first;
	for(auto neighbour : adjList[node]){
    	if(neighbour!=parent){
    		findPath(neighbour,node,second,third,first);
    	}
    }
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	cin>>n;
    	for(int i=1;i<=3;i++){
        	for(int j=1;j<=n;j++)
            	cin>>arr[i][j];
    	}
    	fo(i,n-1){
    		int u,v;
    		cin>>u>>v;
    		adjList[u].pb(v);
    		adjList[v].pb(u);
    	}
    	int root = -1;
    	Fo(i,1,n+1){
    		if(adjList[i].size()>2){
    			cout<<-1<<endl;
    			return 0;
    		}else if(adjList[i].size()==1 && root==-1){
    			root = i;
    		}
    	}

    	int poss[] = {1,2,3};
    	int minima = inf;
    	int first = -1,second = -1,third = -1;
    	do{
			int val=cost(root,-1,poss[0],poss[1],poss[2]);
        	if(val<minima)
        	{
            	minima=val;
            	first=poss[0];
            	second=poss[1];
            	third=poss[2];
        	}
    	}
    	while(next_permutation(poss,poss+3));
    	findPath(root,-1,first,second,third);
    	cout<<minima<<endl;
    	Fo(i,1,n+1)
    		cout<<ans[i]<<" ";
    	cout<<endl;


    }
}
