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
const int N = 3e5+5;
int n,k,p;
int dp[1505][1505];

int solve(int idx,int rem,vvi &a){
    if(idx==n) return 0;
    if(rem==0) return 0;
    if(dp[idx][rem]!=-1) return dp[idx][rem];
    int ans = solve(idx+1,rem,a);
    int sum = 0;
    loop(i,1,k+1){
        sum += a[idx][i-1];
        if(i<=rem){
            ans = max(ans,solve(idx+1,rem-i,a)+sum);
        }else
            break;
    }
    return dp[idx][rem] = ans;
}


int32_t main(){
	get_it_done();
    int T=1;
    cin >> T;
    loop(t,1,T+1){
    	cout<<"Case #"<<t<<": ";
        cin>>n>>k>>p;
        vvi a(n);
        loop(i,0,n){
            loop(j,0,k){
                int x;
                cin>>x;
                a[i].pb(x);
            }
        }
        mset(dp,-1);
        cout<<solve(0,p,a)<<endl;
        

    }
}
