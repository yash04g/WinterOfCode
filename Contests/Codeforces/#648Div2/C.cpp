#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
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

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    map<int,int> m;
    loop(i,0,n){
        cin>>a[i];
        m[a[i]] = i;
    }
    loop(i,0,n){
        cin>>b[i];
    }
    map<int,int> l,r;
    loop(i,0,n){
        int idx = m[b[i]];
        if(idx<i){
            l[i-idx]++;
            r[n-i+idx]++;
        }else if(i==idx){
            l[0]++;
            r[0]++;
        }else{
            r[idx-i]++;
            l[i+n-idx]++;
        }
    }
    int ans = 0;
    for(auto x:l){
        ans = max(ans,x.ss);
    }
    for(auto x:r){
        ans = max(ans,x.ss);
    }
    cout<<ans<<endl;


}

int32_t main(){
    get_it_done();
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
