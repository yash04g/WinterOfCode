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
    cin >> t;
    while (t--){
        int n,p,k;
        cin>>n>>p>>k;
        vi a(n);
        int cost = 0;
        int minima = inf;
        fo(i,n){ 
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int ans = 0;
        Fo(i,1,n+1){
            if(i-k>=0){
                dp[i] = min(dp[i-1]+a[i-1],dp[i-k]+a[i-1]);
            }else{
                dp[i] = dp[i-1]+a[i-1];
            }
            if(dp[i]<=p){
                ans = max(ans,i);
            }
        }
        cout<<ans<<endl;

    }
}
