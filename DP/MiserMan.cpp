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

int fare[105][105];
int dp[105][105];

int cost(int n,int m){
	fo(i,m){
		dp[0][i] = fare[0][i];
	}
	Fo(i,1,n){
		fo(j,m){
			if(j!=0 && j!=m-1){
				dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+fare[i][j];
			}
			if(j==0){
				dp[i][j] = min(dp[i-1][j],dp[i-1][j+1])+fare[i][j];
			}
			if(j==m-1){
				dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+fare[i][j];
			}
		}
	}
	int ans = inf;
	fo(i,m){
		ans = min(dp[n-1][i],ans);
	}
	return ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n,m;
		cin>>n>>m;
		fo(i,n)
			fo(j,m) 
				cin>>fare[i][j];
		cout<<cost(n,m);


    }
}
