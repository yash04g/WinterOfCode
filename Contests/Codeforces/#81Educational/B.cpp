#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mset(a,i) memset(a,i,sizeof(a))
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
#define sp(x,y) fixed<<setprecision(y)<<x

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
const int N = 1e5+5;
int dp[N];
int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        int n,x;
        cin>>n>>x;
        string s;
        cin>>s;
        int b[N];
        int c0=0,c1=0;
        int ans=0;
        loop(i,0,n){
            if(s[i]=='0'){
                c0++;
            }else{
                c1++;
            }
            b[i]=c0-c1;
            if(b[i]==x){
                ans++;
            }
        }
        if(ans>0 && b[n-1]==0){
            cout<<-1<<endl;
            continue;
        }
        if(x==0){
            ans++;
        }
        loop(i,0,n){
            if(b[n-1]!=0){
                double a =(double(x-b[i])/double(b[n-1]));
                if(a==trunc(a) && a>0){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;

    }
}
