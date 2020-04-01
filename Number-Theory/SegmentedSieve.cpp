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
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod; }
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
const int N = 1e6+5;
vector<int> primes;
bool isPrime[N];

void sieve(){
    loop(i,0,N) isPrime[i] = 1;
    isPrime[0] = 0;
    isPrime[1] = 0;
    loop(i,2,N){
        if(isPrime[i]){
            for(int j=i*i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }
    loop(i,2,N){
        if(isPrime[i]) primes.pb(i);
    }
}

void print(int l,int r){
    loop(i,0,N) isPrime[i] = 1;
    for(int i=0;primes[i]*primes[i]<=r;i++){
        int currPrime = primes[i];
        int base = (l/currPrime)*currPrime;
        if(base<l) base += currPrime;
        for(int j=base;j<=r;j+=currPrime){
            isPrime[j-l] = 0;
        }
        if(base==currPrime) isPrime[base-l] = 1;
    }
    loop(i,0,r-l+1){
        if(isPrime[i]) cout<<(i+l)<<endl;
    }
    cout<<endl;
}

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    sieve();
    while (q--){
        int l,r;
        cin>>l>>r;
    }
}
