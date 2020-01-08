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
const int N = 1e5+5;
int dp1[N];
int dp2[N];



int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int n,q;
		cin>>n>>q;
		vi a(n);
		loop(i,0,n) cin>>a[i];
		int fwd[N];
		int rev[N];
		fwd[0] = 0;
		int cnt = 1;
		loop(i,1,n){
			if(a[i]>a[i-1]){
				cnt+=1;
			}else{
				fwd[i-1] = cnt;
				cnt = 1;
			}
		}
		fwd[n-1] = cnt;
		vi prefixSum1(n,0);
		dp1[0] = 0;
		loop(i,1,n){
			dp1[i] = dp1[i-1];
			if(fwd[i]>1){
				dp1[i]+=1;
			}
		}
		loop(i,0,n){
			cout<<dp1[i]<<" ";
		}
		// exit(0);
		cout<<endl;

		prefixSum1[0] = 0;
		loop(i,1,n){
			prefixSum1[i] = prefixSum1[i-1]+dp1[i]; 
		}
		reverse(all(a));
		rev[0] = 0;
		cnt = 1;
		loop(i,1,n){
			if(a[i]>a[i-1]){
				cnt+=1;
			}else{
				rev[i-1] = cnt;
				cnt = 1;
			}
		}
		rev[n-1] = cnt;
		dp2[0] = 0;
		loop(i,1,n){
			dp2[i] = dp2[i-1];
			if(rev[i]>1){
				dp2[i]+=1;
			}
		}
		reverse(dp2,dp2+n);
		loop(i,0,n){
			cout<<dp2[i]<<" ";
		}
		// exit(0);
		// vi prefixSum2(n,0);
		// prefixSum2[0] = 0;
		// loop(i,1,n){
		// 	prefixSum2[i] = prefixSum2[i-1]+dp2[i];
		// }
		// loop(i,0,n){
		// 	cout<<prefixSum1[i]<<" ";
		// }
		// cout<<endl;
		// loop(i,0,n){
		// 	cout<<prefixSum2[i]<<" ";
		// }
		// exit(0);
		while(q--){
			int l,r;
			cin>>l>>r;
			l--;r--;
			int cnt1 = dp1[r]-dp1[l];
			int cnt2 = abs(dp2[r]-dp2[l]);
			// cout<<cnt1<<" "<<cnt2<<endl;
			if(cnt1==cnt2) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}


    }
}
