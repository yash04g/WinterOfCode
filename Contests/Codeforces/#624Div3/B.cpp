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
const int N = 3e5+5;

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        int n,m;
        cin>>n>>m;
        vi a(n);
        loop(i,0,n) cin>>a[i];
        vi p(m);
        loop(i,0,m) cin>>p[i];
        vi b = a;
        sort(all(b));
        if(a==b){
            cout<<"YES"<<endl;
            continue;
        }
        sort(all(p));
        map<int,bool> m1;
        loop(i,0,m) m1[p[i]-1] = 1;
        int i, j;  
        bool flag = 1;
        for (i = 0; i < n-1; i++) {     
            for (j = 0; j < n-i-1; j++)  {
                if (a[j] > a[j+1])  {
                    if(m1[j]){
                    swap(a[j], a[j+1]);
                }else{
                    flag = 0;
                    break;
                }
                }
            }
            }
            if(flag){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        
    }
}
