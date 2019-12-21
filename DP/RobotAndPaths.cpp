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

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int m,n,p;
    	cin>>m>>n>>p;
    	memset(dp,0,sizeof(dp));
    	fo(i,p){
    		int x,y;
    		cin>>x>>y;
    		dp[x-1][y-1] = -1;
    	}
    	if(dp[0][0]==-1){
    		cout<<0<<endl;
    		continue;
    	}
    	fo(i,m){
    		if(dp[i][0]!=-1){
    			dp[i][0] = 1;
    		}else{
    			break;
    		}
    	}
    	fo(i,n){
    		if(dp[0][i]!=-1){
    			dp[0][i] = 1;
    		}else{
    			break;
    		}
    	}
    	Fo(i,1,m){
    		Fo(j,1,n){
    			if(dp[i][j]!=-1){
    				dp[i][j] = 0;
    				if(dp[i-1][j]!=-1){
    					dp[i][j] = (dp[i-1][j]%mod);
    				}
    				if(dp[i][j-1]!=-1){
    					dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
    				}
    			}
    		}
    	}
    	if(dp[m-1][n-1]!=-1){
    		cout<<dp[m-1][n-1]<<endl;
    	}else{
    		cout<<0<<endl;
    	}

    }
}
