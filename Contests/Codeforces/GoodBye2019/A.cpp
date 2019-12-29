#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mii map<int,int>
#define mci map<char,int>  
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

bool compare(int a,int b){
	return a>b;
}

int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	int n,k1,k2;
    	cin>>n>>k1>>k2;
    	vi p1(k1);
    	vi p2(k2);
    	loop(i,0,k1) cin>>p1[i];
    	loop(i,0,k2) cin>>p2[i];
    	sort(p1.begin(),p1.end(),compare);
    	sort(p2.begin(),p2.end(),compare);
    	bool flag = 1;
    	int i=0,j=0;
    	while(i<k1 && j<k2){
    		if(p1[i]>p2[j]){
    			flag = 1;
    			break;
    		}else if(p2[j]>p1[i]){
    			flag = 0;
    			break;
    		}else{
    			i++;
    			j++;
    		}
    	}
    	if(flag){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    	
    }
}
