#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// #define int long long
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
const int N = 2e5+5;
int n;
int a[N];
int pref[N][205];
vector<int> idx[205];

int main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        loop(i,0,205) idx[i].clear();
        int n;
        cin>>n;
        loop(i,1,n+1){
            cin>>a[i];
            idx[a[i]].pb(i);
            loop(j,1,201){
                pref[i][j] = pref[i-1][j];
            }
            pref[i][a[i]]++;
        }
        int ans = 0;
        loop(i,1,201){
            int n1 = idx[i].size();
            ans = max(ans,n1);
            loop(j,0,n1/2){
                int idx1 = idx[i][j];
                int idx2 = idx[i][n1-j-1];
                int midfreq = 0;
                loop(k,1,201){
                    if(k==i) continue;
                    else{
                        midfreq = max(midfreq,pref[idx2][k]-pref[idx1][k]);
                    }
                }
                ans = max(ans,2*(j+1)+midfreq);
            }
        }
        cout<<ans<<endl;
    }
}
