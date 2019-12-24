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
int dp[35][12][2];
int transactions[35];

int solve(int k,int n,int state,int i){
	if(k<=0){
		return 0;
	}
	if(i>=n){
		return 0;
	}
	if(dp[i][k][state]>-1){
		return dp[i][k][state];
	}
	int ans = solve(k,n,state,i+1);
	if(state){
		ans = max(ans,solve(k-1,n,state^1,i+1)+transactions[i]);
	}else{
		if(k>0){
			ans = max(ans,solve(k,n,state^1,i+1)-transactions[i]);	
		}
	}
	return dp[i][k][state] = ans;

}

int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	int k,n;
    	cin>>k>>n;
    	fo(i,n) cin>>transactions[i];
    	memset(dp,-1,sizeof(dp));
    	int ans = solve(k,n,0,0);
    	cout<<ans<<endl;
    }
}
