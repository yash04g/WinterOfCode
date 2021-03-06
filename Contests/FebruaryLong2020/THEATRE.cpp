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
const int N = 3e5+5;
int slots[4][4];
vi ans;

void solve(int idx,set<int> s,vi a1){
    if(idx==4){
        int n1 = 4-s.size();
        sort(all(a1),greater<int>());
        int sum = 0;
        loop(i,0,a1.size()){
            sum += a1[i]*(25*(4-i));
        }
        sum -= n1*100;
        ans.pb(sum);
        return;
    }
    bool flag = 0;
    loop(i,0,4){
        if(s.find(i)!=s.end()) continue;
        if(!slots[idx][i]) continue;
        s.insert(i);
        a1.pb(slots[idx][i]);
        flag = 1;
        solve(idx+1,s,a1);
        s.erase(i);
        a1.pop_back();
    }
    if(!flag) solve(idx+1,s,a1);
}

int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    int p = 0;
    while (t--){
        ans.clear();
        int n;
        cin>>n;
        mset(slots,0);
        while(n--){
            int a;
            char b;
            cin>>b>>a;
            slots[b-65][a/3-1]+=1;
        }
        set<int> s;
        vi a1;
        solve(0,s,a1);
        int cost = 0;
        sort(all(ans),greater<int>());
        cost += ans[0];
        cout<<cost<<endl;
        p += cost;
        
    }
    cout<<p<<endl;
}
