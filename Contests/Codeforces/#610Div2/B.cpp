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

// int solve(vi &a,int n,int p,int i){
// 	if(i>=n)
// 		return 0;
// 	if(p<=0){
// 		return 0;
// 	}
// 	if(dp[i]>-1){
// 		return dp[i];
// 	}
// 	int ans = solve(a,n,p,i+1);
// 	if(i==0){
// 		if(p>=a[i])
// 			ans = max(ans,1+solve(a,n,p-a[i],i+1));
// 	}else{
// 		if(p>=max(a[i-1],a[i]))
// 			ans = max(ans,max(2+solve(a,n,p-max(a[i-1],a[i]),i+1),1+solve(a,n,p-a[i],i+1)));
// 		else if(p>=a[i])
// 			ans = max(ans,1+solve(a,n,p-a[i],i+1));
// 	}	
// 	return dp[i] = ans;

// }

int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
		int n,p,k;
		cin>>n>>p>>k;
		vi a(n);
		fo(i,n) cin>>a[i];
		sort(a.begin(),a.end());
		int cost1 = 0;
		int cost2 = 0;
		int b = p;
		int i=0;
		while(i<n){
			if(a[i] <= b){
				if(i==0){
					cost1 += 1;
					b -= a[i];
				}
				else{
					cost1 += 2;
					b -= a[i];
				}
			}
			else{
				break;
			}
			i += 2;
		}
		b = p;
		int j=1;
		while(j<n){
			if(a[j]<= b){
				cost2 += 2;
				b -= a[j];
			}
			else{
				break;
			}
			j += 2;
		}
		cout<<max(cost1,cost2)<<endl;
    }
}
