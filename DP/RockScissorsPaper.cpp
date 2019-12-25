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
double dp[105][105][105];


void init_dp(){
	fo(i,105){
		fo(j,105){
			fo(k,105){
				dp[i][j][k] = -1.0;
			}
		}
	}
}

double f1(int r,int s,int p){
	if(r==0 || s==0)
		return 0.0;
	if(p==0)
		return 1.0;
	if(dp[r][s][p]!=-1.0)
		return dp[r][s][p];
	double total = r*s+s*p+p*r;
	double ans = 0.0;
	ans += f1(r-1,s,p)*((r*p)/total);
	ans += f1(r,s-1,p)*((r*s)/total);
	ans += f1(r,s,p-1)*((s*p)/total);
	return dp[r][s][p] = ans;
}

double f2(int r,int s,int p){
	if(s==0 || p==0)
		return 0.0;
	if(r==0)
		return 1.0;
	if(dp[r][s][p]!=-1.0)
		return dp[r][s][p];
	double total = r*s+s*p+p*r;
	double ans = 0.0;
	ans += f2(r-1,s,p)*((r*p)/total);
	ans += f2(r,s-1,p)*((r*s)/total);
	ans += f2(r,s,p-1)*((s*p)/total);
	return dp[r][s][p] = ans;
}

double f3(int r,int s,int p){
	if(r==0 || p==0)
		return 0.0;
	if(s==0)
		return 1.0;
	if(dp[r][s][p]!=-1.0)
		return dp[r][s][p];
	double total = r*s+s*p+p*r;
	double ans = 0.0;
	ans += f3(r-1,s,p)*((r*p)/total);
	ans += f3(r,s-1,p)*((r*s)/total);
	ans += f3(r,s,p-1)*((s*p)/total);
	return dp[r][s][p] = ans;
}

int32_t main(){
	// 3
	// 2 2 2
	// 2 1 2
	// 1 1 3
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	int r,s,p;
    	cin>>r>>s>>p;
    	init_dp();	
    	double ans1 = f1(r,s,p); // Rock Survivability
    	init_dp();	
    	double ans2 = f2(r,s,p); // Scissor
    	init_dp();	
    	double ans3 = f3(r,s,p); // Paper survivability
    	cout<<fixed<<setprecision(9)<<"Rock "<<ans1<<"Scissor "<<ans2<<"Paper "<<ans3<<endl;
    }
}
