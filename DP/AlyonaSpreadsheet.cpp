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
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n,m;
		cin>>n>>m;
		vvi a(n,vi(m));
		fo(i,n) fo(j,m) cin>>a[i][j];
		vvi dp(n,vi(m,0));
		fo(i,m) dp[0][i] = 0;
		Fo(i,1,n){
			fo(j,m){
				if(a[i][j]>=a[i-1][j]){
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = i;				}
			}
		}
		vi ans(n);
		ans[0] = 0;
		Fo(i,1,n){
			int res = INT_MAX;
			fo(j,m){
				res = min(res,dp[i][j]);
			}
			ans[i] = res;
		}
		int q;
		cin>>q;
		while(q--){
			int l,r;
			cin>>l>>r;
			l-=1;r-=1;
			if(ans[r]<=l){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}
    }
}
