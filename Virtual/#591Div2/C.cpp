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
const int N = 2e5+5;
int dp[N];
int n;
int x,a,y,b,k;

bool check(int num,vi &p){
    int lcm = (a*b)/gcd(a,b);
    int both = num/lcm;
    int only_a = num/a - both;
    int only_b = num/b - both;
    int val = 0;
    int i = 0;
    for(i=0;i<both;i++){
        val += p[i]*(x+y);
    }
    for(i=both;i<only_b+both;i++){
        val += p[i]*y;
    }
    for(i=only_b+both;i<only_a+only_b+both;i++){
        val += p[i]*x;
    }
    // cout<<val<<endl;
    return val>=k;
}

int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        cin>>n;
        vi p(n);
        loop(i,0,n){ 
            cin>>p[i];
            p[i] /= 100;
        }
        cin>>x>>a>>y>>b>>k;
        sort(all(p),greater<int>());
        if(x>y){
            swap(x,y);
            swap(a,b);
        }
        int ans = -1;
        int start = 1;
        int end = n;
        while(start<=end){
            int mid = (start+end)/2;
            if(check(mid,p)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        cout<<ans<<endl;
    }
}
