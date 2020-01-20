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
void swap(int &a,int &b){
	a^=b;b^=a;a^=b;
}
const int N = 2e5+5;
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        int n,s,k;
        cin>>n>>s>>k;
        vi a(k);
        mii m;
        loop(i,0,k) cin>>a[i],m[a[i]]++;
        if(m[s]==0){
            cout<<0<<endl;
            continue;
        }
        int cnt1 = 0;
        int i=s+1;
        while(i<min(n+1,s+k+1)){
            if(m[i]==0){
                cnt1+=1;
                break;
            }else{
                cnt1+=1;
            }
            i++;
        }
        int cnt2 = 0;
        int j=s-1;
        while(j>max(0ll,s-k-1)){
            if(m[j]==0){
                cnt2+=1;
                break;
            }else{
                cnt2+=1;
            }
            j--;
        }
        int ans = inf;
        if(j==0){
            ans = cnt1;
            cout<<ans<<endl;
            continue;
        }
        if(i==n+1){
            ans = cnt2;
            cout<<ans<<endl;
            continue;
        }
        ans = min(cnt1,cnt2);
        cout<<ans<<endl;


		    	

    }
}
