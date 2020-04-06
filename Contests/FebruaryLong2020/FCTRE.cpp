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
const int N = 1e5+5;
vi adjList[N];
int n,q;
bool visited[N];
vi ans;
void dfs(int src,int des){
    ans.pb(src);
    visited[src] = 1;
    if(src==des){
        return;
    }
    bool flag = 0;
    for(auto x:adjList[src]){
        if(!visited[x]){
            dfs(x,des);
            flag = 1;
        }
    }
    if(!flag) ans.pop_back();
}

int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    while(t--){
        cin>>n;
        loop(i,0,n+1){
            adjList[i].clear();
        }
        loop(i,0,n-1){
            int u,v;
            cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }        
        vi weights(n+1,0);
        loop(i,1,n+1) cin>>weights[i];
        cin>>q;
        while(q--){
            ans.clear();
            mset(visited,0);
            int s,d;
            cin>>s>>d;
            if(s>n || d>n){
                cout<<0<<endl;
                continue;
            }
            dfs(s,d);
            map<int,int> m;
            loop(i,0,ans.size()){
                // deb(ans[i]);
                int temp = weights[ans[i]];
                // deb(temp);
                for(int i=2;i*i<=temp;i++){
                    int cnt1 = 0;
                    while(temp%i==0){
                        cnt1++;
                        temp /= i;
                    }
                    m[i] += cnt1;
                }
                if(temp>1) m[temp]+=1;
            }
            int res = 1;
            for(auto x:m){
                res = (res*((x.ss+1ll)%mod))%mod;
            }
            cout<<res<<endl;
        }

    }
}
