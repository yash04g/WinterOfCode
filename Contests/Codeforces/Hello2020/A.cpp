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
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
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
        int n,m;
        cin>>n>>m;
        vector<string> s1(n);
        vector<string> s2(m);    
        loop(i,0,n) cin>>s1[i];
        loop(i,0,m) cin>>s2[i];
        int q;
        cin>>q;
        while(q--){
            int a;
            cin>>a;
            string ans = "";
            int x = a%n; 
            int y = a%m;
            if(x==0){
                ans += s1[n-1];
            }else{
                ans += s1[x-1];
            }
            if(y==0){
                ans += s2[m-1];
            }else{
                ans += s2[y-1];    
            }
            
            cout<<ans<<endl;
        }

    }
}
