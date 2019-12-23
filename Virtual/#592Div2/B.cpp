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
    cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	int cntz = 0;
    	fo(i,n){
    		if(s[i]=='0')
    			cntz++;
    	}
    	if(cntz==n){
    		cout<<n<<endl;
    		continue;
    	}
    	if(cntz==0){
    		cout<<2*n<<endl;
    		continue;
    	}
    	// int idx = -1;
    	int cnt = n;
    	fo(i,n){
    		if(s[i]=='1'){
    			cnt = max(cnt,(i+1)*2);
    		}
    	}
    	for(int i=n-1;i>=0;i--){
    		if(s[i]=='1'){
    			cnt = max(cnt,(n-i)*2);
    		}
    	}
    	cout<<cnt<<endl;
    }
}
