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
int cnt = 0;
int start1 = -1;
int end1 = -1;
 
int maxSubArraySum(int *a, int size) { 
    int max_so_far = -inf, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here){ 
            max_so_far = max_ending_here; 
            cnt++;
        }
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
}  
 
int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        int a[N];
        int y = 0;
        loop(i,0,n) cin>>a[i],y+=a[i];
        int ad1 = maxSubArraySum(a,n-1);
        int ad2 = maxSubArraySum(a+1,n-1);
        int ad = max(ad1,ad2);
        if(ad>=y){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }
}