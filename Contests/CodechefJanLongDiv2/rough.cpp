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

void longestBitonicSubarray(int *a, int n){
	dp1[0] = 1;
	if(a[1]>a[0]){
    	dp1[1] = 2;
    }else{
    	dp1[1] = 1;
    }
	loop(i,2,n){
		dp1[i] = 1;
		for(int j=i-1;j>=0;j--){
			if(a[j]<a[i]){
				dp1[i] = max(dp1[i],dp1[j]+1);
			}
		}
	}
	dp2[n-1] = 1;
	if(a[n-2]>a[n-1]){
		dp2[n-2] = 2;
	}else{
		dp2[n-2] = 1;
	}
	for(int i=n-3;i>=0;i--){
		dp2[i] = 1;
		for(int j=i+1;j<n;++j){
			if(a[j]<a[i]){
				dp2[i] = max(dp2[i],dp2[j]+1);
			}
		}
	}
	
}


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int a[100005];
		int n,q;
		cin>>n>>q;
		loop(i,0,n) cin>>a[i];

		longestBitonicSubarray(a,n);
		int prefixSum1[N],prefixSum2[N];
		prefixSum1[0] = 0;
		prefixSum2[0] = 0;
		loop(i,0,n){
			if(dp1[i]==1){
				prefixSum1[i] = prefixSum1[i-1];
			}else{
				prefixSum1[i] = prefixSum1[i-1]+dp1[i-1];
			}
			if(dp2[i]==1){
				prefixSum2[i] = prefixSum2[i-1];
			}else{
				prefixSum2[i] = prefixSum2[i-1]+dp2[i-1];
			}
		}

		while(q--){
			int l,r;
			cin>>l>>r;
			l--;r--;
			int cnt1 = prefixSum1[r]-prefixSum1[l];
			int cnt2 = prefixSum2[r]-prefixSum2[l];
			cout<<cnt1<<" "<<cnt2<<endl;
			if(cnt1==cnt2) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}

    }
}
