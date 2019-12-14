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
int dp1[N];
int dp2[N];

int longestBitonicSubarray(int *a, int n){
	dp1[0] = 1;
	if(a[1]>a[0]){
    	dp1[1] = 2;
    }else{
    	dp1[1] = 1;
    }
	Fo(i,2,n){
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
	int ans1 = 0;
	fo(i,n){
		ans1 = max(ans1,dp1[i]+dp2[i]-1);
	}
	return ans1;
	
}


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
		int a[100005];
		int n;
		cin>>n;
		fo(i,n){
			cin>>a[i];
		}   
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		cout<<longestBitonicSubarray(a,n)<<endl;
    }
}
