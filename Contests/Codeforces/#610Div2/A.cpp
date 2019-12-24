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
    	int a,b,c,r;
    	cin>>a>>b>>c>>r;
    	int x1 = c-r;
    	int x2 = c+r;
    	int time = 0;
    	if(a>b){
    		a ^= b;
    		b ^= a;
    		a ^= b;
    	}
    	if(a<=x1){
    		time += (x1-a);
    	}else{
    		if(a>x2){
    			cout<<b-a<<endl;
    			continue;
    		}
    	}
    	if(b>=x2){
    		time += (b-x2);
    	}else{
    		if(b<x1){
    			cout<<b-a<<endl;
    			continue;
    		}
    	}
    	cout<<time<<endl;
    }
}
