#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mii map<int,int>
#define mci map<char,int>  
#define pii pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18
#define sp(x,y) fixed<<setprecision(y)<<x
 
void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
void swap(int &a,int &b){
	a^=b;b^=a;a^=b;
}
const int N = 1e5+5;
int dp[N];
int n;
int height[N];

int solve(int i){
    if(dp[i]!=-1) return dp[i];
    if(i>=n){
        return inf;
    }
    if(i==(n-1)){
        return 0;
    }
    int ans = inf;
    ans = min(abs(height[i]-height[i+1])+solve(i+1),abs(height[i]-height[i+2])+solve(i+2));
    return dp[i] = ans;
}
 
int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n;
        loop(i,0,n) cin>>height[i];
        memset(dp,-1,sizeof(dp));
        // cout<<solve(0);
        dp[0] = 0;
        dp[1] = abs(height[1]-height[0]);
        loop(i,2,n){
            dp[i] = min(abs(height[i]-height[i-2])+dp[i-2],abs(height[i]-height[i-1])+dp[i-1]);
        }
        cout<<dp[n-1]<<endl;
 
 
    }
}