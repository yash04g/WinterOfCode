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
    	int n,m;
    	cin>>n>>m;
    	if(m>n){
    		cout<<0<<endl;
    		continue;
    	}
    	if(m==1){
    		int x = n/10*45;
    		int y = n%10;
    		int ans = x+(y*(y+1)/2);
    		cout<<ans<<endl;
    		continue;
    	}
    	if(m%10==0){
    		cout<<0<<endl;
    		continue;
    	}
    	int ld = m%10;
    	int x = n/m;
    	int ans = 0;
    	if(ld&1){
    		if(ld==5){
    			ans += (x-(x%2))*5/2;
    			if(x&1) ans += 5;
    		}else{
    			ans += (x-(x%10))*45/10;
    			for(int i=1;i<=(x%10);++i){
    				ans += (i*ld)%10;
    			}
    			
    		}
    	}else{
    		ans += (x-(x%5))*20/5;
    		for(int i=1;i<=(x%5);++i){
    				ans += (i*ld)%10;
    		}
 	
    	}
    	cout<<ans<<endl;

    }
}
