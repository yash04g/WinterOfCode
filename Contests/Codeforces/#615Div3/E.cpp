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
const int N = 2e5+5;
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        loop(i,0,n) loop(j,0,m) cin>>a[i][j];
        int ans = 0;
        loop(j,0,m){
            mii mp;
            loop(i,0,n){
                if((a[i][j]-j-1ll)%m==0 && (a[i][j]-j-1ll)/m<n){
                    int moves;
                    if((a[i][j]-j-1ll)/m <= i){
                        moves = i-(a[i][j]-j-1ll)/m;
                    }else{
                        moves = n - ((a[i][j]-1ll)/m)+ i;
                    }
                    mp[moves] += 1;
                }
            }
            int mini = n;
            for(auto x:mp){
                mini = min(mini,x.ff-x.ss+n);
            }
            ans += mini;

        }
        cout<<ans<<endl;

    }
}
