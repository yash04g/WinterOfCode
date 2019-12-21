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
int dp[1005][1005];
int a[105];

int sum(int s,int e){
	int ans = 0;
	for(int i=s;i<=e;++i){
		ans += a[i];
		ans %= 100;
	}
	return ans;
}

int numMixtures(int i,int j){
	if(i>=j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	int ans = INT_MAX;
	for(int k=i;k<=j;++k){
		int temp = numMixtures(i,k) + numMixtures(k+1,j) + sum(i,k)*sum(k+1,j);
		ans = min(ans,temp);
	}
	return dp[i][j] = ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n;
		cin>>n;    	
		fo(i,n) cin>>a[i];
		// exit(0);
		memset(dp,-1,sizeof(dp));
		cout<<numMixtures(0,n-1)<<endl;
    }	
}
