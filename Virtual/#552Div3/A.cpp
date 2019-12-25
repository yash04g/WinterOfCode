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
    	int x1,x2,x3,x4;
    	cin>>x1>>x2>>x3>>x4;
    	int sum = max(x1,max(x2,max(x3,x4)));
    	int a = sum-x1;
    	int b = sum-x2;
    	int c = sum-x3;
    	if(a==0){
    		a = sum-x4;
    	}
    	if(b==0){
    		b = sum-x4;
    	}
    	if(c==0){
    		c = sum-x4;
    	}
    	cout<<a<<" "<<b<<" "<<c<<endl;
    }
}
