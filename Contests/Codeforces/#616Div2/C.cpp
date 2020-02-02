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
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
const int N = 3505;
int arr[N];
int dp[N][N];
int n,m,k;

int solve(int s,int e){
    int curr = n-abs(e-s);
    if(curr==m){
        return dp[s][e] = max(arr[e],arr[s]);
    }
    if(dp[s][e]!=-1) return dp[s][e];
    int ans = 0;
    if(curr<=k){
        ans = max(solve(s+1,e),solve(s,e-1));
    }else{
        ans = min(solve(s+1,e),solve(s,e-1));
    }
    return dp[s][e] = ans;
}

int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        cin>>n>>m>>k;
        loop(i,1,n+1){
            cin>>arr[i];
        }
        if(m==1){
            cout<<max(arr[1],arr[n])<<endl;
            continue;
        }
        loop(i,0,n+1)loop(j,0,n+1)dp[i][j]=-1;
        cout<<solve(1,n)<<endl;
    }
}
