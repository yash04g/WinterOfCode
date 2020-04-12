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
const int N = 1e6+5;
bool isPrime[N];
vi primes;
void precompute(){
    isPrime[0] = 0;
    isPrime[1] = 0;
    loop(i,2,N){
        if(isPrime[i]){
            primes.pb(i);
            for(int j=i*2;j*j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    loop(i,0,N) isPrime[i] = 1;; 
    precompute();
    while (q--){
        int n;
        cin>>n;
        int ans = 0;
        ans = (ans+n)%mod;
        set<int> s;
        map<int,vi> m1;
        loop(i,0,primes.size()){
            if(primes[i]*primes[i]>n) break;
            else{
                int num = primes[i]*primes[i];
                while(num<=n){
                    m1[primes[i]].pb(num);
                    s.insert(num);
                    num *= primes[i];
                }
            }
        }
        // for(auto x:m1){
        //     cout<<x.ff<<" ";
        //     loop(i,0,x.ss.size()){
        //         cout<<x.ss[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        vi temp = m1[2];
        for(auto x:m1){
            if(x.ff==2) continue;
            else{
                loop(i,0,temp.size()){
                    loop(j,0,x.ss.size()){
                        if(temp[i]*x.ss[j]>n) break;
                        else s.insert((temp[i]*x.ss[j]));
                    }
                }
            }
        }
        // loop(i,0,sq.size()) cout<<sq[i]<<" ";
        // cout<<endl;
        for(auto x:s){
            deb(x);
            int val = n/x;
            val = val*x;
            ans = (ans+val)%mod;
        }
        cout<<ans<<endl;

    }
}