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
int dp[N];
int res[N];

int phi(int n){
    memset(res,0,sizeof(res));
    loop(i,0,N){
        dp[i] = i;
    }
    loop(i,2,N){
        if(dp[i]==i){
            dp[i] -= 1;
            for(int j=i*2;j<N;j+=i){
                dp[j] = (dp[j]*(i-1))/i;
                // deb(j,dp[j]);
            }
        }
    }   

    loop(i,1,N){
        for(int j=i;j<N;j+=i){
            res[j] += (i*dp[i]);
        }
    }
    return res[n];
}

void func(int n){
    int ans = phi(n);
    ans += 1;
    ans *= n;
    ans /= 2;
    cout<<ans<<endl;
}

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        int n;
        cin>>n;
        func(n);
        
    }
}
