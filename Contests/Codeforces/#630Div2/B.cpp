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
const int N = 3e5+5;
bool isPrime[1005];
int dp[1005];

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        int n;
        cin>>n;
        vi a(n);
        map<int,bool> m1;
        loop(i,0,n) cin>>a[i],m1[a[i]]=1;
        mset(dp,-1);
        loop(i,0,n){
            isPrime[i] = 1;
        }
        isPrime[0] = 0;
        isPrime[1] = 0;
        int c = 1;
        loop(i,2,1005){
            bool flag = 0;
            if(m1[i] && dp[i]==-1){
                dp[i] = c;
                flag = 1;
            }
            if(isPrime[i]){
                for(int j=i*2;j<1005;j+=i){
                    isPrime[j] = 0;
                    if(m1[j] && dp[j]==-1){
                        dp[j] = c;
                        flag = 1;
                    }
                }
            }
            if(flag) c+=1;
        }
        cout<<c-1<<endl;
        loop(i,0,n) cout<<dp[a[i]]<<" ";
        cout<<endl;
        
    }
}
