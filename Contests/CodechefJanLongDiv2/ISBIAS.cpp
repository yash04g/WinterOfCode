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
int n,q;
int a[N],dp1[N],dp2[N];
int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	cin>>n>>q;
    	loop(i,1,n+1) cin>>a[i];
    	memset(dp1,0,sizeof(dp1));
    	memset(dp2,0,sizeof(dp2));
		int curr = 0, prev = 0;
		int inc = 0, dec = 0;
		loop(i,1,n){
			prev = curr;
			if(a[i]<a[i+1]){
				curr = 1;
			}
			else{
				curr = 0;
			}
			if(curr == 1 && prev == 0){
				inc++;
			}
			dp1[i+1] = inc;
		}
		curr = 1, prev = 1;
		loop(i,1,n){
			prev = curr;
			if(a[i]>a[i+1]){
				curr = 0;
			}else{
				curr = 1;
			}
			if(curr == 0 && prev == 1){
				dec++;
			}
			dp2[i+1] = dec;
		}
		loop(i,1,n+1){
			cout<<dp1[i]<<" ";
		}
		cout<<endl;
		loop(i,1,n+1){
			cout<<dp2[i]<<" ";
		}

		while(q--){
			int l,r; 
			cin>>l>>r;
			int cnt1=0,cnt2=0;
			if(l+1 == r){
				cout<<"NO"<<endl;
				continue;
			}
			cnt1 = dp1[r] - dp1[l];
			cnt2 = dp2[r] - dp2[l];
			if(dp1[l] == dp1[l+1] && a[l] < a[l+1]){
				cnt1++;
			}
			if(dp2[l] == dp2[l+1] && a[l] > a[l+1]){
				cnt2++;
			}
			
			if(cnt1==cnt2){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}

    }
}
