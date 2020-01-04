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
        int n;
        cin>>n;
        vi a;
        loop(i,0,n){
            int y;
            cin>>y;
            a.pb(y);
        }
        vi ans;
        loop(i,0,n){
            if(a[i]==1){
                a.pb(1);
            }else{
                break;
            }
        }
        int n1 = a.size();
        int cnt = 0;
        loop(i,0,n1){
            // cout<<a[i]<<" ";
            if(a[i]==1){
                cnt += 1;
            }else{
                ans.pb(cnt);
                cnt = 0;
            }
        }
        ans.pb(cnt);
        // cout<<endl;
        int n2 = ans.size();
        sort(all(ans));
        cout<<ans[n2-1]<<endl;


    }
}
