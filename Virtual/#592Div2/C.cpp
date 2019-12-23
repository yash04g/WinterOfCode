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


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n,p,w,d;
    	cin>>n>>p>>w>>d;
    	if(p==0){
    		cout<<0<<" "<<0<<" "<<n<<endl;
    		continue;
    	}
    	if(w*n-p<0){
    		cout<<-1<<endl;
    	}else{
    		fo(i,w+1){
    			if((p-(i*d)) %w ==0){
    				int x = (p-i*d)/w;
    				if(x>=0){
    					cout<<x<<" "<<i<<" "<<n-x-i<<endl;
    					return 0;
    				}
    			}
    		}
    		cout<<-1<<endl;
    	}
    }
}
