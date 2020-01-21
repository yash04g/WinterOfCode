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
string s1,s2;
int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>s1>>s2;
        int n1 = s1.size();
        int n2 = s2.size();
        int a[n2];
        int j = n2-1;
        rloop(i,n1-1,0){
            if(j>=0 && s1[i]==s2[j]){
                a[j] = i;
                j--;
            }
        }
        cout<<a[0]<<" "<<a[1]<<endl;
        int x1 = a[0];
        int x2 = n1-a[n2-1];
        cout<<x1<<" "<<x2<<endl;
        int ans = max(x1,x2);
        cout<<ans<<endl;


    }
}
