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
const int N = 1e3+5;
int dp[N][N];

int coinChange(int n,int *d,int numD){
	if(n==0) return 1;
	if(n<0 || numD<=0) return 0;
	if(dp[n][numD]!=-1){
		return dp[n][numD];
	}
	int change1 = coinChange(n-d[0],d,numD);
	int change2 = coinChange(n,d+1,numD-1);
	return dp[n][numD] = change1+change2;
}
int coinChangeDP(int n,int *d,int numD){
	memset(dp,-1,sizeof(dp));
	
	fo(i,numD) dp[0][i] = 1;

	Fo(i,1,n+1){
		Fo(j,0,numD){
			int x,y;
			// Denomination Included
			if(i-d[j]>=0){
				x = dp[i-d[j]][j];
			}else{
				x = 0;
			}
			// Not included
			if(j>=1){
				y = dp[i][j-1];
			}else{
				y = 0;
			}
			dp[i][j] = x+y;
		}
	}
	return dp[n][numD-1];

}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	memset(dp,-1,sizeof(dp));
    	int d[100005];
    	int numD;
    	cin>>numD;
    	int n;
    	cin>>n;
    	fo(i,numD) cin>>d[i];
    	cout<<coinChange(n,d,numD)<<endl;
    }	
}
