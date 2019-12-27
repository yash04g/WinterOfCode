#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// #define int long long
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
    int T=1;
    cin >> T;
    Fo(t,1,T+1){
    	cout<<"Case #"<<t<<": ";
    	int n;
    	cin>>n;
    	vi a(n);
    	fo(i,n) cin>>a[i];
    	vi ans(n,0);
    	ans[0] = 1;
    	priority_queue<int,vector<int>,greater<int> > s;
    	s.push(a[0]);
    	Fo(i,1,n){
    		if(a[i]>ans[i-1]){
    			s.push(a[i]);
    		}
    		int cnt= 0;
    		for(int j=0;j<s.size();++j){
    			// deb(x);
    			if(s.top()<=ans[i-1])
    				s.pop();
    			else 
    				break;
    			// cnt++;
    			// cout<<cnt<<endl;
    		}
    		if(s.size()>=(ans[i-1]+1)){
    			// cout<<1<<endl;
    			ans[i] = ans[i-1]+1;
    		}else{
    			ans[i] = ans[i-1];
    		}
    	}
    	for(auto x:ans)
    		cout<<x<<" ";
    	cout<<endl;
    }
}
