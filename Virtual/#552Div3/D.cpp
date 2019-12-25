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
    	int n,capb,capa;
    	cin>>n>>capb>>capa;
    	vi s(n);
    	fo(i,n) cin>>s[i];
    	int a = capa;
    	int b = capb;
    	if(a==0){
    		cout<<min(n,b)<<endl;
    		continue;
    	}
    	if(b==0){
    		cout<<min(n,a)<<endl;
    		continue;
    	}
    	int dist = 0;
    	fo(i,n){
    		if(a==0 && b==0){
    			break;
    		}
    		if(s[i]==1){
    			if(a==capa){
    				a -= 1;
    				dist += 1;
    			}else if(b>0){
    				b -= 1;
    				dist += 1;
    				a += 1;
    			}else{
    				a -= 1;
    				dist += 1;
    			}
    		}else{
    			if(a>0){
    				a -= 1;
    				dist += 1;
    			}else{
    				b -= 1;
    				dist += 1;
    			}
    		}
    	}
    	cout<<dist<<endl;
    }
}
