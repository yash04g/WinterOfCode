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
const int N = 5e2+5;
int dp[505][105];

int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}

int count(vi &a,int n){
	memset(dp,0,sizeof(dp));
	fo(i,n){
		dp[i][0] = 0;
	}
	dp[0][a[0]] = 1;
	for(int i=1;i<n;i++){
		dp[i][a[i]] += 1;
		for(int j=i;j>=0;j--){
			if(a[j]<a[i]){
				for(int g=1;g<=100;g++){
					if(dp[j][g]>0){
						int newg = gcd(g,a[i]);
						dp[i][newg] = (dp[i][newg]+dp[j][g])%mod;
					}
				}
			}
		}
	}
	int ans = 0;
	fo(i,n){
		ans = (ans+dp[i][1])%mod;
	}	
	return ans;

}
	

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n;
		cin>>n; 
		vi a(n);
		fo(u,n) cin>>a[u];
		int ans = count(a,n);
		cout<<ans<<endl;
    }
}
