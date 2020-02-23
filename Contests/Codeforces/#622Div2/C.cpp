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
    // cin >> q;
    while (q--){
        int n;
        cin>>n;
        vi a(n);
        loop(i,0,n) cin>>a[i];
        vi b = a;
        sort(all(b));
        if(b==a){
            loop(i,0,n){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        sort(all(b),greater<int>());
        if(b==a){
            loop(i,0,n){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        int ans = 0;
        vi ans_s(n);
        vi temp (n);
        loop(i,0,n){
            int tempans = a[i];
            temp[i] = a[i];

            loop(j,i+1,n){
                if(a[j]>temp[j-1]){
                    temp[j] = temp[j-1];
                    tempans += temp[j];
                }else{
                    temp[j] = a[j];
                    tempans += temp[j];
                }
        }

        rloop(j,i-1,0){
            if(a[j]>temp[j+1]){
                temp[j] = temp[j+1];
                tempans += temp[j];
            }
            else{
                temp[j] = a[j];
                tempans += temp[j];
            }
        }
        if(tempans>ans){
            ans = tempans;
            loop(j,0,n){
                ans_s[j] = temp[j];
            }
        }
    }
        loop(i,0,n){
            cout<<ans_s[i]<<" ";
        }
    }
}
