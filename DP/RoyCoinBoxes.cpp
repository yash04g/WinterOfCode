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
    	int n,m;
    	cin>>n>>m;
    	vi boxes(n+1,0);
    	vi start(n+1,0);
    	vi end(n+1,0);
    	while(m--){
    		int l,r;
    		cin>>l>>r;
    		start[l] += 1;
    		end[r] += 1;
    	}
    	boxes[1] = start[1];
    	Fo(i,2,n+1){
    		boxes[i] = boxes[i-1]+start[i]-end[i-1];
    	}
    	// int s = 1e6+5;
    	vi cnt(n+1,0);
    	fo(i,n+1){
    		cnt[boxes[i]]++;
    	}
    	vi atleast(n+1,0);
    	atleast[n] = cnt[n];
    	for(int i=n-1;i>0;i--){
    		atleast[i] = atleast[i+1]+cnt[i];
    	}
    	int q;
    	cin>>q;
    	while(q--){
    		int count;
    		cin>>count;
    		cout<<atleast[count]<<endl;
    	}
    }
}
