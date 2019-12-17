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
#define inf 1e9
#define pdd pair<double,double>

void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
const int N = 1e5+5;
// int dp[N];
pdd trip[3005];
double fun[3005];

double dis(pdd d1,pdd d2){
	return sqrt(pow(d1.first-d2.first,2)+pow(d2.second-d1.second,2));
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n;
		cin>>n;
		fo(i,n){
			double x,y;
			cin>>x>>y>>fun[i];
			trip[i] = mp(x,y);
		}
		double dp[3005];
		memset(dp,0,sizeof(dp));
		dp[0] = fun[0];
		for(int i=1;i<n;i++){
			dp[i] = -inf;
			for(int j=0;j<i;++j){
				double sad = dis(trip[i],trip[j]);
				dp[i] = max(dp[i],dp[j]-sad);
			}
			dp[i] += fun[i];
		}
		double ans = -inf;
		fo(i,n){
			ans = max(dp[i],ans);
		}
		cout<<fixed<<setprecision(7)<<ans<<endl;
    }
}
