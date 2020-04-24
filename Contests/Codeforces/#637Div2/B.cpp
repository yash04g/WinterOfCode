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

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        int n,k;
        cin>>n>>k;
        vi a(n);
        loop(i,0,n) cin>>a[i];
        vi prefSum(n+1,0);
        loop(i,1,n-1){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                prefSum[i]++;
            }
        }      
        loop(i,1,n){
            prefSum[i] += prefSum[i-1];
        }
        int maxCnt = prefSum[k-2];
        int idx = 0;
        loop(i,k,n){
            int cnt = prefSum[i-1]-prefSum[i-k+1];
            if(cnt>maxCnt){
                idx = i-k+1;
                maxCnt = cnt;
            }
        }
        cout<<maxCnt+1<<" "<<idx+1<<endl;
        
    }
}
