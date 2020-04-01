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
class Triplet{
public:
    int x;
    int y;
    int g;
};

Triplet extendedEuclid(int a,int b){
    if(b==0){
        Triplet ans;
        ans.g = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet temp = extendedEuclid(b,a%b);
    Triplet ans;
    ans.g = temp.g;
    ans.x = temp.y;
    ans.y = temp.x - (a/b)*temp.y;
    return ans;
}
int mmI(int a,int m){
    Triplet ans = extendedEuclid(a,m);
    return (ans.x+m)%m; // As x can be negative as well
}

int32_t main(){
    get_it_done();
    int q=1;
    // cin >> q;
    while (q--){
        int a;
        int b;
        cin>>a>>b;
        Triplet ans = extendedEuclid(a,b);
        cout<<ans.x<<" "<<ans.y<<" "<<ans.g<<endl;
    }
}
