// https://codeforces.com/contest/1082/problem/D
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
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
const int N = 505;
int n;
int a[N];
vi leaves;
vi non_leaves;
vpii ans;

void addEdge(int x,int y){
    a[x]--;
    a[y]--;
    ans.pb(mp(x,y));
}

int poss(){
    loop(i,0,non_leaves.size()){
        if(a[non_leaves[i]]>0){
            return i;
        }
    }
}


int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n;
        loop(i,1,n+1) cin>>a[i];
        int sum = 0;
        loop(i,1,n+1) sum += a[i];
        if(sum<(2*n-2)){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES ";
        
        loop(i,1,n+1){
            if(a[i]==1) leaves.pb(i);
            else non_leaves.pb(i);
        }
        int dm = non_leaves.size()-1;
        if(leaves.size()==1){
            dm += 1;
        }
        if(leaves.size()>1){
            dm += 2;
        }
        cout<<dm<<endl<<n-1<<endl;
        loop(i,1,non_leaves.size()){
            addEdge(non_leaves[i],non_leaves[i-1]);
        }
        loop(i,0,leaves.size()){
            if(i==0){
                addEdge(leaves[i],non_leaves[0]);
            }else if(i==1){
                addEdge(leaves[i],non_leaves[non_leaves.size()-1ll]);
            }else{
                int idx = poss();
                addEdge(leaves[i],non_leaves[idx]);
            }
        }
        for(auto x:ans){
            cout<<x.ss<<" "<<x.ff<<endl;
        }


    }
}
