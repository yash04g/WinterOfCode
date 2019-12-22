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
int dp[105][105][105];

int solve(string s1,string s2,int k){
	int m = s1.length();
	int n = s2.length();
	if(k<=0){
		return 0;
	}
	if(m<=0 || n<=0){
	    return INT_MIN;
	}
	if(dp[m][n][k] != -1){
		return dp[m][n][k];
	}
	int ans = 0;
	if(s1[0]==s2[0]){
		ans = max(s1[0]+solve(s1.substr(1),s2.substr(1),k-1),max(solve(s1,s2.substr(1),k),solve(s1.substr(1),s2,k)));
	}else{
		ans = max(solve(s1.substr(1),s2,k),solve(s1,s2.substr(1),k));
	}
	return dp[m][n][k] = ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
		string s1,s2;
		cin>>s1>>s2;
		int k;
		cin>>k;
		memset(dp,-1,sizeof(dp));
		int ans = 0;
		ans = solve(s1,s2,k);
		if(ans<0) ans = 0;
		cout<<ans<<endl;
    }
}
