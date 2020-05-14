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

int32_t main(){
    get_it_done();
    int tc=1;
    cin >> tc;
    while (tc--){
        int n;
        cin>>n;
        if(n<4){
            cout<<-1<<endl;
            continue;
        }
        bool visited[1005];
        mset(visited,0);
        vi ans;
        ans.pb(n);
        int prev = n;
        visited[n] = 1;
        loop(i,1,n){
            if(prev-2>=1 && !visited[prev-2]){
                int el = prev-2;
                prev = el;
                ans.pb(el);
                visited[el] = 1;
            }else if(prev-3>=1 && !visited[prev-3]){
                int el = prev-3;
                prev = el;
                ans.pb(el);
                visited[el] = 1;
            }else if(prev-4>=1 && !visited[prev-4]){
                int el = prev-4;
                prev = el;
                ans.pb(el);
                visited[el] = 1;
            }else if(prev+2<n && !visited[prev+2]){
                int el = prev+2;
                prev = el;
                ans.pb(el);
                visited[el] = 1;
            }else if(prev+3<n && !visited[prev+3]){
                int el = prev+3;
                prev = el;
                ans.pb(el);
                visited[el] = 1;
            }else if(prev+4<n && !visited[prev+4]){
                int el = prev+4;
                prev = el;
                ans.pb(el);
                visited[el] = 1;
            }
        }
        loop(i,0,ans.size()){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
}
