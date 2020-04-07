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
int a[505][5005];
int n,m,k;
vi ans;

void solve(){
    vi freq(k,0);
    loop(i,0,n){
        map<int,int> m1;
        int mini=inf;
        loop(j,0,k){
            if(mini>freq[j]){
                mini=freq[j];
            }
        }
        loop(j,0,k){
            if(freq[j]==mini){
                m1[a[i][j]]++;    
            }
        }
        int maxi = 0;
        int val1 = 1;
        for(auto x:m1){
            if(x.ss>maxi){
                maxi=x.ss;
                val1=x.ff;
            }
        }
        ans[i]=val1;
        loop(j,0,k){  
            if(a[i][j]==val1){
                freq[j]++;
            }
        }
    }
}

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while(q--){
        cin>>n>>m>>k;
        ans.clear();
        ans.resize(n,0);
        loop(i,0,n){
            loop(j,0,k){
                cin>>a[i][j];
            }
        }
        solve();
        loop(i,0,n) cout<<ans[i]<<" ";
        cout<<endl;
        
    }
}
