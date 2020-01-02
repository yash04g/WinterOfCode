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
    // cin >> t;
    while (t--){
    	string s;
    	cin>>s;
    	int cnt = 0;
    	reverse(s.begin(),s.end());
    	int n = s.size();
    	if(n==1 && s[0]=='0'){
    		cout<<0<<endl;
    		continue;
    	}
    	bool flag = true;
    	int cnt1 = 0;
    	fo(i,n){
    		if(!(i&1)){
    			cnt += 1;
    		}
    		if(s[i]=='1')
    			cnt1 += 1;
    	}
    	if(!((n-1)&1) && cnt1==1)
    		cnt -= 1;
    	cout<<cnt<<endl;

    }
}
