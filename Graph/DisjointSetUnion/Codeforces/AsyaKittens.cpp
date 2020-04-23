// https://codeforces.com/problemset/problem/1131/F
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
int n;
int parent[N];
pii arr[N];
vi vec[N];

void build(){
    loop(i,0,n+1){
        parent[i] = i;
        arr[i].first = i;
        arr[i].second = i;
    }
}
 
int find(int a){
    if(parent[a] == a) 
        return a;
    return parent[a] = find(parent[a]);
}
 
void make_union(int a, int b){
    int r_a = find(a);
    int r_b = find(b);
 
    if(r_a != r_b){
        parent[r_b] = r_a; 
        vec[ arr[r_a].second ].pb(arr[r_b].first); 
        arr[r_a].second = arr[r_b].second;   
    }
}

int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n;
        build();
        loop(i,0,n-1){
            int u,v;
            cin>>u>>v;
            make_union(u,v);
        }        
        int i = find(1);
        while(1){
            cout<<i<<" ";
            if(vec[i].size()>0) i = vec[i][0];
            else break;
        }

    }
}
