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
    int n, m;
	cin>>n>>m;
	vi A(n);
	vi B(n);
	int sumA = 0, sumB = 0;
	fo(i,n){
		cin>>A[i];
	}
	fo(i,n){
		cin>>B[i];
		if(B[i]==0){
			B[i] += m;
		}
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	vi diff(n);
	int idx = 0;
	while(1){
		fo(i,n){
			int id = (i + idx)%n;
			diff[i] = B[id] - A[i];
			if(diff[i]==m){
				diff[i] = 0;
			}
			if(diff[i]<0){
				diff[i] += m;
			}
		}
		sort(diff.begin(),diff.end());
		if(diff[0]==diff[n-1]){
			break;
		}
		else{
			idx++;
		}
	}
	cout<<diff[0]<<endl;
    }
}
