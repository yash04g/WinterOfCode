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

int matrixMultiply(vi &a,int i,int j){
	if(i==j){
		return dp[i][j] = 0;
	}
	if(dp[i][j]!=-1) return dp[i][j];
	int ans = INT_MAX;
	for(int k=i;k<j;++k){
		int temp = matrixMultiply(a,i,k)+matrixMultiply(a,k+1,j)+a[i-1]*a[k]*a[j];
		ans = min(ans,temp);
	}
	return dp[i][j] = ans;
}
int mcmDP(vi &a){
	memset(dp,-1,sizeof(dp));
	int n = a.size();
	for(int i=1;i<n;i++){
		dp[i][i] = 0;
	}
	for(int len = 2;len<n;len++){
		for(int i=1;i<=n-len;++i){
			int j = i+len-1;
			dp[i][j] = INT_MAX;
			for(int k=i;k<j;k++){
				int newAns = dp[i][k]+dp[k+1][j] + a[i-1]*a[k]*a[j];
				dp[i][j] = min(dp[i][j],newAns);
			}
		}
	}
	return dp[1][n-1];
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n;
		cin>>n;
		vi a(n);
		fo(i,n) cin>>a[i];
		memset(dp,-1,sizeof(dp));
		cout<<matrixMultiply(a,1,n-1)<<endl;		
		cout<<mcmDP(a)<<endl;
    }
}
