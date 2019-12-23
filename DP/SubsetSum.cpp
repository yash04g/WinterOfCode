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
bool dp[2][1005];

bool solve(vi &a,int sum,int n){
	memset(dp,0,sizeof(dp));
	fo(i,2){
		dp[i][0] = 1;
	}
	fo(i,sum+1){
		dp[0][i] = 0;
	}
    dp[0][0] = 1;
    bool flag = 1;
	Fo(i,1,n+1){
		Fo(j,1,sum+1){
			dp[flag][j] = dp[flag^1][j];
			if(j-a[i-1]>=0){
				dp[flag][j] = dp[flag^1][j] || dp[flag^1][j-a[i-1]];
			}
		}
		flag ^= 1;
	}
	return dp[flag^1][sum];
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
    	int sum;
    	cin>>sum;
    	bool ans = solve(a,sum,n);
    	if(ans){
    		cout<<"Yes"<<endl;
    	}else{
    		cout<<"No"<<endl;
    	}
    }
}
