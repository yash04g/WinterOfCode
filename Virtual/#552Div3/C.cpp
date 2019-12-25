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
    	int a,b,c;
    	cin>>a>>b>>c;
   		int l1 = a/3;
   		int l2 = b/2;
   		int l3 = c/2;
   
   		int n = min(l1, l2);
   		n = min(n, l3);
   
   		int maxi = 0;
   
   		Fo(i,1,8){
        	int a1, b1, c1;
        	a1 = a - 3*n;
        	b1 = b - 2*n;
        	c1 = c - 2*n;  
        
        	int cnt = 0;
        
        	while(1){
            int day = (i + cnt);
            	if(day > 7)
                	day-=7;
            	if(day == 1 || day == 4 || day == 7)
                	a1--;
            	else if(day == 2 || day == 6)
                	b1--;
           	 	else c1--;
            	
            	if(a1>=0 && b1>=0 && c1>=0)
            	    cnt++;
            	else break;    
        	}
        
        	maxi = max(maxi, cnt);
   		}
   
   		cout<<(maxi + 7*n);

    }
}
