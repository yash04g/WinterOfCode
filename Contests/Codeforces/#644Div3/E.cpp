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
int n;
int arr[55][55];
void solve(){
    cin>>n;
    string s[n];
    loop(i,0,n){
        cin>>s[i];
        loop(j,0,n) {
            if(s[i][j]=='1'){
                arr[i][j] = 1;
            }else{
                arr[i][j] = 0;
            }
        }
    }
    int dp[n][n];
    mset(dp,0);
    loop(i,0,n){
        dp[i][n-1] = arr[i][n-1];
    }
    loop(i,0,n){
        dp[n-1][i] = arr[n-1][i];
    }
    bool flag = 1;
    rloop(i,n-2,0){
        rloop(j,n-2,0){
            if(arr[i][j]){
                dp[i][j] = dp[i+1][j] | dp[i][j+1];
            }else{
                dp[i][j] = 0;
            }
            if(dp[i][j]!=arr[i][j]){
                flag = 0;
                break;
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int32_t main(){
    get_it_done();
    int tc=1;
    cin >> tc;
    while (tc--){
        solve();        
    }
}
