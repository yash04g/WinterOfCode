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
#define pii pair<int,int>
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { if(0) return; cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){   
    if(0) return; 
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
void get_it_done(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int gcd(int a,int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}
const int N = 1e6+5;
int factors[N];
int dp[12][N];
bool isPrime[N];
void sieve(){
    mset(factors,0);
    loop(i,0,N) isPrime[i] = 1;
    isPrime[0] = 0;
    isPrime[1] = 0;
    loop(i,2,N){
        if(isPrime[i]){
            factors[i] += 1;
            for(int j=i*2;j<N;j+=i){
                isPrime[j] = 0;
                factors[j] += 1;
            }
        }
    }
}

void precompute(){
    mset(dp,0);
    loop(i,1,12){
        loop(j,1,N){
            dp[i][j] += dp[i][j-1];
            if(factors[j]==i) dp[i][j] += 1;
        }
    }
}


int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    sieve();
    precompute();  
    while(q--){
        int a,b,n;
        cin>>a>>b>>n;
        if(a==1 && n==0){
            cout<<1<<endl;
            continue;
        }
        int ans = dp[n][b]-dp[n][a-1];
        cout<<ans<<endl;              
    }
}
