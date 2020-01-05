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
const int N = 1e4+5;
int dp[105][105][105][2];
int n;
int arr[N];

int func(int e,int o,int i,int p){
    if(e<0 || o<0)
        return inf;
    if(i>=n)
        return 0;
    if(dp[e][o][i][p]!=-1)
        return dp[e][o][i][p];
    int ans = inf;
    if(arr[i]==0){
        ans = min(func(e-1,o,i+1,0)+p,func(e,o-1,i+1,1)+1-p);
    }else{
        ans = func(e,o,i+1,arr[i]%2)+abs(arr[i]%2-p);
    }
    return dp[e][o][i][p] = ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n;
        mii m;
        loop(i,0,n) cin>>arr[i],m[arr[i]]++;
        memset(dp,-1,sizeof(dp));
        int numo = 0;
        int nume = 0;
        loop(i,1,n+1){
            if(m[i]>0) continue;
            else{
                if(i&1) numo++;
                else nume++;
            }
        }
        // cout<<nume<<" "<<numo<<endl;
        cout<<min(func(nume,numo,0,1),func(nume,numo,0,0))<<endl;

    }
}
