#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
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

void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void swap(int &a,int &b){
	a^=b;b^=a;a^=b;
}
const int N = 2e5+5;
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
		int n;
		cin>>n;
		vi a(n+1);
		int mini = inf;
		int maxi = -1;
		loop(i,1,n+1) cin>>a[i];
		bool flag = false;
		vi ans;
		loop(i,1,n){
			if(abs(a[i]-a[i+1])>=2){
				ans.pb(i);
				ans.pb(i+1);
				flag = true;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
			cout<<ans[0]<<" "<<ans[1]<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		


		

    }
}
