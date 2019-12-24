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
const int N = 1e5+5;
int dp[10005][5005];
vpii salary(N);

int solve(int n,int i,int x){
	if(i>=n){
		return 0;
	}
	if(dp[i][x]>-1)
		return dp[i][x];
	if(x==0){
		return dp[i][x] = salary[i].second + solve(n,i+1,x+1);	
	}
	if(x==(n-i)){
		return dp[i][x] = salary[i].first + solve(n,i+1,x-1);
	}
	return dp[i][x] = min(salary[i].second + solve(n,i+1,x+1),salary[i].first + solve(n,i+1,x-1));
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	fo(i,n){
    		int x,y;
    		cin>>x>>y;
    		salary[i] = mp(x,y);
    	}
    	memset(dp,-1,sizeof(dp));
    	int ans = solve(n,0,0);
    	cout<<ans<<endl;

    }
}
