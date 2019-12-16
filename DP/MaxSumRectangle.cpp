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
int dp[N];

int kadane(vi &a){
	int ans = 0;
	int sum = 0;
	for(int i=0;i<a.size();i++){
		if(sum+a[i]>0){
			sum += a[i];
		}else{
			sum = 0;
		}
		ans = max(ans,sum);
	}
	return ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int m,n;
    	cin>>m>>n;
    	int grid[105][105];
    	fo(i,m) fo(j,n) cin>>grid[i][j];
    	vi sum(m);
    	int ans = 0;
    	fo(l,n){
    		vi sum(m,0);
    		Fo(r,l,n){
    			fo(j,m){
    				sum[j] += grid[j][r];
    			}
    			ans = max(kadane(sum),ans);
    		}
    	}
    	cout<<ans<<endl;
    }
}
