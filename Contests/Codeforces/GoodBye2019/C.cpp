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
    	vi a(n);
    	int sum = 0;
    	int xr = 0;
    	loop(i,0,n) cin>>a[i],sum+=a[i],xr^=a[i];
    	if(sum==2*xr){
    		cout<<0<<endl;
    		cout<<""<<endl;
    		continue;
    	}
    	if(sum==xr){
    		if(!(sum&xr)){
    			cout<<2<<endl;
    			cout<<sum/2<<" "<<sum/2<<endl;
    			continue;
    		}else{
    			cout<<2<<endl;
    			cout<<sum<<" "<<2*sum<<endl;
    			continue;
    		}
    	}
    	if(xr==0){
    		cout<<1<<endl;
    		cout<<sum<<endl;
    		continue;
    	}
	    int x = xr;
	    int y = sum+xr;
	    cout<<2<<endl;
	    cout<<x<<" "<<y<<endl;


    }
}
