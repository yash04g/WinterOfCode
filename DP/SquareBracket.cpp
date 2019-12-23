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
int dp[100][100];

int solve(int open,int close,int n,vector<bool> &positions){	
	if(open==n && close==n) return 1;
	if(open>n || close>n) return 0;
	int currIdx = open+close;
	if(dp[open][currIdx]!=-1){
		return dp[open][currIdx];
	}
	if(open==close || positions[currIdx]){
		return dp[open][currIdx] = solve(open+1,close,n,positions);
	}else{
		if(open==n){
			return dp[open][currIdx] = solve(open,close+1,n,positions);
		}else{
			return dp[open][currIdx] = solve(open,close+1,n,positions)+solve(open+1,close,n,positions);
		}
	}
}

int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
		int n,k;
		cin>>n>>k;
		vector<bool> positions(2*n+1,0);
		fo(i,k){
			int x;
			cin>>x;
			positions[x-1] = true;
		}    	
		memset(dp,-1,sizeof(dp));
		cout<<solve(0,0,n,positions)<<endl;
    }
}
