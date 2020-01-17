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
const int N = 3e3+5;
double dp[N][N];
int n;
double a[N];


int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n;
        loop(i,1,n+1) cin>>a[i];
        int numHeads = n/2+1;
        int numTails = n/2;
        mset(dp,0);
        dp[0][0] = 1;
        loop(i,1,n+1){
            double head = a[i];
            double tail = 1-a[i];
            dp[0][i] = tail*dp[0][i-1];
            loop(h,1,i+1){
                dp[h][i] = (head*dp[h-1][i-1])+(tail*dp[h][i-1]);
            }
        }
        double ans = 0;
        loop(i,n/2+1,n+1){
            ans += dp[i][n];
        }
        cout<<sp(ans,10)<<endl;



    }
}
