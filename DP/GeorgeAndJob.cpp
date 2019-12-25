// https://codeforces.com/contest/467/problem/C
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
int n,m,k;
int dp[5005][5005];
int arr[5005];

int solve(int i,int k){
	if(i>=n+1){
		if(k==0){
			return 0;
		}
		return -inf;
	}
	if(dp[i][k]!=-1){
		return dp[i][k];
	}
	int ans = -inf;
	ans = max(ans,solve(i+1,k));
	if(i+m-1<=n && k){
		ans = max(ans,arr[i+m-1]-arr[i-1]+solve(i+m,k-1));
	}
	return dp[i][k] = ans;

}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	
    	cin>>n>>m>>k;
    	arr[0] = 0;
    	Fo(i,1,n+1){
    		cin>>arr[i];
    		arr[i] += arr[i-1];
    	}
    	memset(dp,-1,sizeof(dp));
    	cout<<solve(1,k);
    }
}
