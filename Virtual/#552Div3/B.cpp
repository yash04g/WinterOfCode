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
    	int n;
    	cin>>n;
    	vi a(n);
    	fo(i,n) cin>>a[i];
    	sort(all(a));
    	set<int> s;
    	fo(i,n) s.insert(a[i]);
    	if(s.size()==2){
    		auto it = s.begin();
    		int x1 = *it;
    		it++;
    		int x2 = *(it);
    		if((x2-x1)&1){
    			cout<<x2-x1<<endl;
    			continue;
    		}else{
    			cout<<(x2-x1)/2<<endl;
    			continue;
    		}
    	}
    	if(s.size()==1){
    		cout<<0<<endl;
    		continue;
    	}
    	if(s.size()>3){
    		cout<<-1<<endl;
    		continue;
    	}else{
    		auto it = s.begin();
    		int x1 = *it;
    		it++;
    		int x2 = *(it);
    		it++;
    		int x3 = *(it);
    		if(x2-x1==x3-x2){
    			cout<<(x2-x1)<<endl;
    			continue;
    		}else{
    			cout<<-1<<endl;
    			continue;
    		}

    	}

    }
}
