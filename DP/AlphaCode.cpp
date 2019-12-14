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
int a[100005];


int count(int n){
	if(n==1 || n==0){
		return 1;
	}
	int output1 = count(n-1);
	if(a[n-2]*10+a[n-1] <= 26){
		output1 += count(n-2);
	}
	return output1;

}
int countMem(int n){
	if(n==1 || n==0){
		return 1;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	int output1 = count(n-1);
	if(a[n-2]*10+a[n-1] <= 26){
		output1 += count(n-2);
	}
	return dp[n] = output1;
}

int countDp(int n){
	dp[0] = 1;
	dp[1] = 1;
	Fo(i,2,n+1){
		dp[i] = dp[i-1];
		if(a[n-2]*10+a[n-1]<=26){
			dp[i] += dp[i-2];
		}
	}
	return dp[n];
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	fo(i,n) cin>>a[i];
    	cout<<count(n)<<endl;
    	memset(dp,0,sizeof(dp));
    	cout<<countMem(n)<<endl;
    	memset(dp,0,sizeof(dp));
    	cout<<countDp(n)<<endl;
    }
}
