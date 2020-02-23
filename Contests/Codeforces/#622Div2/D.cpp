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

bool isPeak(vi a, int n, int num, int i, int j){ 
  
    // If num is smaller than the element 
    // on the left (if exists) 
    if (i >= 0 && a[i] > num){ 
        if(a[i]==num){
            if(j<n && a[j]<num){
                return true;
            }
        }
        return false; 
    }
  
    // If num is smaller than the element 
    // on the right (if exists) 
    if (j < n && a[j] >= num) 
        return false; 
    return true; 
}
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
        int cnt = 0;
        int maxi = -1;
        int idx = -1;
        for (int i = 0; i < n; i++) { 
  
        // If the current element is a peak 
        if (isPeak(a, n, a[i], i - 1, i + 1)){
            cnt++;
            // cout<<i;
            if(maxi < a[i]){
                maxi = a[i];
                idx = i;
            }
        } 
        }
        // deb(cnt);
        // deb(maxi);
        // deb(idx);
        if(cnt==1){
            loop(i,0,n){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        vi c = a;
        int sum1 = c[0];
        loop(i,1,n){
            if(c[i]>c[i-1]){
                c[i] = c[i-1];
            }
            sum1 += c[i];
        }
        vi d = a;
        int sum2 = d[n-1];
        rloop(i,n-2,0){
            if(d[i]>d[i+1]){
                d[i] = d[i+1];
            }
            sum2 += d[i];
        }
        vi e = a;
        int sum3 = e[idx];
        rloop(i,idx-1,0){
            if(e[i]>e[i+1]){
                // deb(e[i]);
                e[i] = e[i+1];
            }
            sum3 += e[i];
        }
        loop(i,idx+1,n){
            if(e[i]>e[i-1]){
                // deb(e[i]);
                e[i] = e[i-1];
            }
            sum3 += e[i];
        }
        if(sum1>sum2){
            if(sum3>sum1){
                // cout<<1<<endl;
                loop(i,0,n) cout<<e[i]<<" ";
            }else{
                // cout<<2<<endl;
                loop(i,0,n) cout<<c[i]<<" ";
            }
        }else{
            if(sum3>sum2){
                // cout<<3<<endl;
                loop(i,0,n) cout<<e[i]<<" ";
            }else{
                // cout<<4<<endl;
                loop(i,0,n) cout<<d[i]<<" ";
            }
        }


        
    }
}
