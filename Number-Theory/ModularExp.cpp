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

int modExp(int a,int b,int m){
    if(a==0) return 0;
    if(b==0) return 1;
    int ans;
    if(b&1){
        int val = modExp(a,b-1,m);
        ans = a%m;
        ans = (ans*val)%m;
    }else{
        int val = modExp(a,b/2,m);
        ans = (val*val)%m;
    }
    return (ans+m)%m;
}

int modExpIterative(int a,int b,int m){
    if(a==0) return 0;
    if(b==0) return 1;
    int ans=1;
    a %= m;
    while(b){
        if(b&1) ans = (ans*a)%m;
        b = b>>1;
        a = (a*a)%m;
    }
    return ans;
}

int32_t main(){
    get_it_done();
    int q=1;
    // cin >> q;
    while (q--){
        int a,b,m;
        cin>>a>>b>>m;
        cout<<modExp(a,b,m)<<endl;
        cout<<modExpIterative(a,b,m)<<endl;
    }
}
