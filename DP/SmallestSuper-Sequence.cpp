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
int dp[1005][1005];

int helper(string s1,string s2,int i,int j){
	int m = s1.size();
	int n = s2.size();
	if(i==m)
		return 1005;
	if(j==n)
		return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	int op1 = helper(s1,s2,i+1,j);
	int idx = -1;
	for(int k=j;k<n;++k){
		if(s1[i]==s2[k]){
			idx = k;
			break;
		}
	}
	if(idx==-1) return 1;
	int op2 = 1+helper(s1,s2,i+1,idx+1);
	return dp[i][j] = min(op1,op2);
}

int solve(string s1,string s2){
	memset(dp,-1,sizeof(dp));
	int ans = helper(s1,s2,0,0);
    if(ans>=1005) ans = -1;
    return ans;
}
int solveDP(string s1,string s2){
	int m = s1.size();
	int n = s2.size();
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=m;i++)
		dp[i][0] = 1;
	for(int i=0;i<=n;i++)
		dp[0][i] = 1005;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			int idx = -1;
			for(int k=j-1;k>=0;k--){
				if(s1[i-1]==s2[k]){
					idx = k;
					break;
				}
			}
			if(idx==-1){
				dp[i][j] = 1;
			}else{
				dp[i][j] = min(dp[i-1][j],1+dp[i-1][idx]);
			}
		}
	}
	int ans = dp[m][n];
	if(ans>=1005)
		ans = -1;
	return ans;


}


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	string s1,s2;
    	cin>>s1>>s2;
    	cout<<solve(s1,s2)<<endl;
    	cout<<solveDP(s1,s2)<<endl;
    }
}
