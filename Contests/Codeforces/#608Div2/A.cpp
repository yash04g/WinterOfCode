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


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		if(e>f){
			int cost1 = min(a,d)*e;
			d -= min(a,d);
			int cost2 = (min(b,min(c,d)))*f;
			int ans = cost1+cost2;
			cout<<ans<<endl;
		}else{
			int cost1 = (min(b,min(c,d)))*f;
			d -= min(b,min(c,d));
			int cost2 = min(a,d)*e;
			int ans = cost1+cost2;
			cout<<ans<<endl;
		} 	
    }
}
