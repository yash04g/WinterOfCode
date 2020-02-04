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
const int N = 2e5+5;
int n,a,b,k;
int arr[N];
int dp[N];

int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n>>a>>b>>k;
        loop(i,0,n){
            cin >> arr[i];
        }
    int ans = 0;
    vi r;
    loop(i,0,n){
        int cost = a+b;
        int temp = arr[i] % cost;
        if (temp == 0)
        {
            temp += cost;
        }
        if (temp > a)
        {
            temp -= a;
            r.pb(ceil((double(temp) / (double(a)))));
        }
        else
        {
            ans++;
        }
    }
    sort(all(r));
    int temp = 0;
    loop(i,0,r.size()){
        temp += r[i];
        if(temp<=k) ans++;
    }
    cout << ans << endl;

    }
}
