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
int a[1000005];
int prefixSum[1000005];

int32_t main(){
	get_it_done();
	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum = 0;
		memset(prefixSum,0,sizeof(prefixSum));
		prefixSum[0] = 1;
		fo(i,n){
			cin>>a[i];
			sum += a[i];
			sum %= n;
			sum = (sum+n)%n;
			prefixSum[sum]++;
		}
		int ans = 0;
		fo(i,n){
			int no = prefixSum[i];
			ans += (no*(no-1)/2);
		}
		cout<<ans<<endl;

	}
}
