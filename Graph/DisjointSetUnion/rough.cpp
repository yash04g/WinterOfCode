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
int dp[N];
int parent[N],size[N];
void initialize(int n){
    loop(i,1,n+1) size[i] = 1,parent[i] = i;
}
int find_parent(int a){
    while(parent[a]!=a){
        a = parent[a];
    }
    return a;
}
bool isConnected(int a,int b){
    if(find_parent(a)==find_parent(b)) return true;
    return false;
}
void union_nodes(int a,int b){
    int r_a = find_parent(a);
    int r_b = find_parent(b);
    if(size[r_a]<size[r_b]){
        parent[r_a] = r_b;
        size[r_b] += size[r_a];
    }else{
        parent[r_b] = r_a;
        size[r_a] += size[r_b];
    }
}



int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        int n,m;
        cin>>n>>m;
        initialize(n);
        loop(i,0,m){
            int u,v;
            cin>>u>>v;
            union_nodes(u,v);
            set<int> s;
            for(int i=1;i<=n;i++){
                int p = find_parent(i);
                s.insert(p);
            }
            vector<int> ans;
            for(auto x:s){
                ans.push_back(size[x]);
            }
            sort(ans.begin(),ans.end());
            for(auto x:ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
}
