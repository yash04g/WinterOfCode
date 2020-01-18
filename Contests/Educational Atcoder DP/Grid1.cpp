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
#define mset(a,i) memset(a,i,sizeof(a))
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
const int N = 1e3+5;
int dp[N][N];
char path[N][N];
int n,m;
 
int solve(int i,int j){
    if(i==n-1 && j==m-1)
        return 1;
    if(i>=n || j>=m)
        return -inf;
    if(dp[i][j]!=-1) return dp[i][j];
 
    int ans = 0;
    if(path[i][j]=='#') 
        return -inf;
    int ans1 = solve(i,j+1);
    int ans2 = solve(i+1,j);
    if(ans1<0) ans1 = 0;
    if(ans2<0) ans2 = 0;
    ans = (ans1+ans2)%mod;
    return dp[i][j] = ans%mod;
}
 
int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n>>m;
        loop(i,0,n) loop(j,0,m) cin>>path[i][j];
        mset(dp,-1);
        int ans = solve(0,0);
        ans %= mod;
        if(ans==(-inf)){
            ans = 0;
        }
        cout<<ans<<endl;
    }
}