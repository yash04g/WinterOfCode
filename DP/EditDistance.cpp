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

int distanceMem(string s1,string s2){
	int m = s1.size();
	int n = s2.size();
	if(m<=0){
		return n;
	}
	if(n<=0){
		return m;
	}
	if(dp[m][n]!=0){
		return dp[m][n];
	}
	int ans = -1;
	if(s1[0]==s2[0]){
		ans = distanceMem(s1.substr(1),s2.substr(1));
	}else{
		ans = 1+min(distanceMem(s1.substr(1),s2.substr(1)),min(distanceMem(s1.substr(1),s2),distanceMem(s1,s2.substr(1))));
	}
	return dp[m][n] = ans;
}

int distance(string s1,string s2){
	memset(dp,0,sizeof(dp));
	int m = s1.size();
	int n = s2.size();
	fo(i,m+1){
		dp[i][0] = i;
	}
	fo(i,n+1){
		dp[0][i] = i;
	}
	Fo(i,1,m+1){
		Fo(j,1,n+1){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
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
		string s1,s2;
		cin>>s1>>s2;
		cout<<distance(s1,s2)<<endl;   
		memset(dp,0,sizeof(dp));
		cout<<distanceMem(s1,s2)<<endl; 	
    }
}
