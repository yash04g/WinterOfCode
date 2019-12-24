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

int dp[10005][1005];
    
    int superEggDrop(int k, int n) {
        for(int i=0;i<=k;i++){
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        for(int j=0;j<=n;j++){
            dp[j][1] = j;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                int ans = 1e9;
                for(int x=1;x<=i;x++){
                    int res = 1+max(dp[x-1][j-1],dp[i-x][j]);
                    ans = min(ans,res);
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][k];
    }

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n,k;
    	cin>>n>>k;
    	// 
    	memset(dp,0,sizeof(dp));
    	cout<<superEggDrop(k,n)<<endl;
    }
}
