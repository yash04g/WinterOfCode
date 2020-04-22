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
const int N = 4e5+5;

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        int n,k;
        cin>>n>>k;
        vi a(n);
        loop(i,0,n) cin>>a[i];
        vi pref(2*k+2,0);
        map<int,int> freq;
        loop(i,0,n/2){
            freq[a[i]+a[n-i-1]]++;
            int left = min(a[i],a[n-i-1])+1;
            int right = max(a[i],a[n-i-1])+k;
            pref[left] += 1;
            pref[right+1] -= 1;
        } 
        loop(i,2,2*k+2){
            pref[i] += pref[i-1];
        }
        int mini = 1e9;
        loop(i,2,2*k+1){
            int cnt0 = freq[i];
            int cnt1 = pref[i]-cnt0;
            int cnt2 = (n/2)-cnt1-cnt0;
            mini = min(mini,cnt1+cnt2*2);
        }
        cout<<mini<<endl;

        
        
    }
}
