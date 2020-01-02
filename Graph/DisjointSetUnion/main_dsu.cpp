#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mii map<int,int>
#define mci map<char,int>  
#define pii pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

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
void swap(int &a,int &b){
    a^=b;b^=a;a^=b;
}
const int N = 2e5+5;
int parent[N],sz[N],mx[N],mn[N];

void initialize(int n){
    loop(i,1,n+1) sz[i] = 1,parent[i] = i,mx[i] = i,mn[i]=i;
}
int find_parent(int a){
    if(parent[a]==a)
        return a;
    return find_parent(parent[parent[a]]);
}
bool isConnected(int a,int b){
    if(find_parent(a)==find_parent(b)) return true;
    return false;
}
int union_nodes(int a,int b){
    int r_a = find_parent(a);
    int r_b = find_parent(b);
    if(r_a==r_b){
        return 0;
    }
    if(sz[r_a]<sz[r_b]){
        parent[r_a] = r_b;
        sz[r_b] += sz[r_a];
        mx[r_b] = max(mx[r_a],mx[r_b]);
        mn[r_b] = min(mn[r_a],mn[r_b]);
    }else{
        parent[r_b] = r_a;
        sz[r_a] += sz[r_b];
        mx[r_a] = max(mx[r_a],mx[r_b]);
        mn[r_a] = max(mn[r_a],mn[r_b]);
    }
    return 1;
}
int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        int n,m;
        cin>>n>>m;
        initialize(n);
        // cout<<1<<endl;
        loop(i,0,m){
            int u,v;
            cin>>u>>v;
            union_nodes(u,v);
        }
    }
}
