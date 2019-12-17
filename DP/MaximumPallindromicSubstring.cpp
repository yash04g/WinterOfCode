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
const int N = 1e5+5;
int dp[10005];
bool prime[10005];
void sieve(){
	fo(i,10005) prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;
	for(int i=2;i*i<=10005;i++){
		if(prime[i]){
			for(int j=i*i;j<10005;j += i){
				prime[j] = false;
			}
		}
	}
}
int len(string s){
	
}

int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    sieve();
    while (t--){
		string s;
		cin>>s;
		int ans = len(s);
		if(prime[ans]){
			cout<<"PRIME"<<endl;
		}else{
			cout<<"NOT PRIME"<<endl;
		}
    }
}
