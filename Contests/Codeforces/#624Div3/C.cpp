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
        string s;
        cin>>s;
        vi a(m);
        loop(i,0,m) cin>>a[i];
        int ans[26];
        mset(ans,0);
        sort(all(a));
        map<int,vector<int> > m1;
        vi temp(26,0);
        temp[s[0]-'a'] = 1;
        m1[0] = temp;
        loop(i,1,n){
            char x = s[i];
            vi a1(26,0);
            a1[x-'a'] = 1;
            vi a2 = m1[i-1];
            loop(i,0,26){
                a1[i] += a2[i];
            }
            m1[i] = a1;
        }
        loop(i,0,m){
            vi x = m1[a[i]-1];
            loop(i,0,26){
                ans[i] += x[i];
            }
        }
        loop(i,0,n){
            ans[s[i]-'a']++;
        }
        loop(i,0,26){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
}
