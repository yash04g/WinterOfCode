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

int dp[105][505];

int solve(vi &fun,vi &cost,int budget,int n){
	memset(dp,-1,sizeof(dp));
	fo(i,n+1){
		dp[i][0] = 0;
	}
	fo(i,budget+1){
		dp[0][i] = 0;
	}
	int ans = 0;
	Fo(i,1,n+1){
		Fo(j,1,budget+1){
			dp[i][j] = dp[i-1][j];
			if(j-cost[i-1]>=0){
				dp[i][j] = max(dp[i][j],fun[i-1]+dp[i-1][j-cost[i-1]]);
			}
		}
	}
	fo(i,budget+1){
		if(dp[n][i]==dp[n][budget]){
			ans = i;
			break;
		}
	}
	cout<<ans<<" ";
	return dp[n][budget];
}


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    int budget,n;
    cin>>budget>>n;
    while (budget!=0 && n!=0){
    	vi cost(n);
    	vi fun(n);
    	fo(i,n){
    		cin>>cost[i]>>fun[i];
    	}
    	cout<<solve(fun,cost,budget,n)<<endl;
    	cin>>budget>>n;
    }
}
