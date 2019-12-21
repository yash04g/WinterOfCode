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
const int N = 2e3+5;
int dp[N][N][8];
vi x,y;
int m,n;


int kOrderedlcs(int i,int j,int k){
	if(i==m || j==n) return 0;
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	int res = 0;
	if(x[i]==y[j]){
		res = 1+kOrderedlcs(i+1,j+1,k);
	}
	else{ 
		if(k>0){
			res = 1+kOrderedlcs(i+1,j+1,k-1);
		}
		res = max(res,kOrderedlcs(i+1,j,k));
		res = max(res,kOrderedlcs(i,j+1,k));
	}
	return dp[i][j][k] = res; 
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int k;
    	cin>>m>>n>>k;
    	fo(i,m){
    		int temp;
    		cin>>temp;
    		x.pb(temp);
    	}
    	fo(i,n){
    		int temp;
    		cin>>temp;
    		y.pb(temp);	
    	}
    	memset(dp,-1,sizeof(dp));
    	cout<<kOrderedlcs(0,0,k)<<endl;
    }
}
