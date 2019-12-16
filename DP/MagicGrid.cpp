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
const int N = 5e2+5;
int dp[N][N];

int minCost(int grid[505][505],int i,int j,int m,int n){
	memset(dp,-1,sizeof(dp));
	dp[m][n-1] = 1;
	dp[m-1][n] = 1;
	dp[m][n] = 1;
	for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
			int healthNeeded = min(dp[i+1][j],dp[i][j+1])-grid[i][j];
			if(healthNeeded<=0){
				dp[i][j] = 1;
			}else{
				dp[i][j] = healthNeeded;
			}
		}
	}
	return dp[0][0];
}

int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	int r,c;
    	cin>>r>>c;
    	int grid[505][505];
    	fo(i,r){
    		fo(j,c){
    			cin>>grid[i][j];
    		}
    	}
    	int cost = minCost(grid,0,0,r,c);
    	cout<<cost<<endl;
    }
}
