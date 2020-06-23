#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds1;

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
    vi a(n+1,0);
    loop(i,1,n+1) cin>>a[i];
    if(n==1){
        cout<<(a[1]*a[1])<<endl;
        return;
    }
    sort(all(a));
    vi freq(21,0);
    loop(i,1,n+1){
        int num = a[i];
        rloop(j,20,0){
            int mask = (1ll<<j);
            if(mask&num){
                freq[j]++;
                num ^= mask;
            }
        }
    }
    vi arr(n+1,0);
    loop(i,1,n+1){
        int num = 0;
        loop(j,0,21){
            if(freq[j]){
                int mask = (1ll<<j);
                num |= mask;
                freq[j]--;
            }
        }
        arr[i] = num;
    }
    int ans = 0;
    loop(i,1,n+1){
        ans += (arr[i]*arr[i]);
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
