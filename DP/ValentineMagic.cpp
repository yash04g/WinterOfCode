// https://hack.codingblocks.com/app/contests/1043/p/825
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
int n,m;
int dp[5005][5005];
int boys[5005];
int girls[5005];

int solve(int i,int j){
	if(i>=n){
		return 0;
	}
	if(j>=m){
		return inf;
	}
	if(dp[i][j]>-1)
		return dp[i][j];
	int ans = min(abs(boys[i]-girls[j])+solve(i+1,j+1),solve(i,j+1));
	return dp[i][j] = ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	
    	cin>>n>>m;
    	memset(dp,-1,sizeof(dp));
    	fo(i,n) cin>>boys[i];
    	fo(i,m) cin>>girls[i];
    	sort(boys,boys+n);
		sort(girls,girls+m);
    	cout<<solve(0,0)<<endl;
    }
}
