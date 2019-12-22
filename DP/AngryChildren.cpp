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

int solve(vi& candies,int n,int k){
	int initialCost = 0;
	int sumSoFar = candies[1];
	for(int i=2;i<=k;i++){
		initialCost += (i-1)*(candies[i])-sumSoFar;
		sumSoFar += candies[i];
	}
	// deb(initialCost);
    int newCost = 0;
    int ans = initialCost;
    int subCost = 0;
    for(int i=2;i<=k;i++){
        subCost += candies[i];
    }
    for(int i=2;i<=n-k+1;i++){
        newCost = initialCost - 2*subCost+(k-1)*(candies[i-1]+candies[k+i-1]);
        subCost = subCost-candies[i]+candies[k+i-1];
        ans = min(ans,newCost);
        initialCost = newCost;
        // deb(newCost);
    }
    return ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n,k;
    	cin>>n>>k;
    	vi candies(n+1);
    	candies[0] = INT_MAX;
    	Fo(i,1,n+1) cin>>candies[i];
    	sort(candies.begin()+1,candies.end());
    	cout<<solve(candies,n,k)<<endl;
    }
}
