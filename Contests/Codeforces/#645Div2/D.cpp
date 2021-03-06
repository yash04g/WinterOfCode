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

void solve(){
    int n,x;
    cin>>n>>x;
    vi a(2*n+1,0);
    loop(i,1,n+1){
        cin>>a[i];
        a[i+n] = a[i];
    }
    vi pref1(2*n+1,0);
    vi pref2(2*n+1,0);
    loop(i,1,2*n+1){
        pref1[i] = pref1[i-1]+a[i];
        pref2[i] = pref2[i-1]+a[i]*(a[i]+1)/2;
    }
    int maxi = 0;
    rloop(i,2*n,n){
        int low = 1;
        int high = i;
        int idx = i;
        while (low<=high){
            int mid = (low + high) / 2;
            if(pref1[i]-pref1[mid-1]>=x){
                idx = mid;
                low = mid+1;
            }else {
                high = mid-1;
            }
            // deb(low,high,idx);
        }
        // deb(idx);
        int cnt = pref1[i]-pref1[idx-1]-x;
        int ans = pref2[i]-pref2[idx-1];
        ans -= (cnt*(cnt+1))/2;
        maxi = max(maxi, ans);
    }
    cout<<maxi<<endl;

}

int32_t main(){
    get_it_done();
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
