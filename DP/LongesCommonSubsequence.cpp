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

int lcs(string s,string t){
	int m = s.size();
	int n = t.size();
	if(m==0 || n==0){
		return 0;
	}
	if(dp[m][n]!=-1){
		return dp[m][n];
	}
	if(s[0]==t[0]){
		return dp[m][n] = 1+lcs(s.substr(1),t.substr(1));
	}else{
		return dp[m][n] = max(lcs(s.substr(1),t),lcs(s,t.substr(1)));
	}
}
int lcsDP(string s,string t){
	int m = s.size();
	int n = t.size();
	memset(dp,0,sizeof(dp));

	fo(i,s.size()){
		dp[i][0] = 0;
	}
	fo(i,t.size()){
		dp[0][i] = 0;
	}
	Fo(i,1,s.size()+1){
		Fo(j,1,t.size()+1){
			if(s[i-1]==t[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];

}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		string x,y;
		cin>>x>>y;
		memset(dp,-1,sizeof(dp));
		cout<<lcs(x,y)<<endl;
		cout<<lcsDP(x,y)<<endl;
    }
}
