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

struct cmp{
    bool operator()(pii a, pii b){
        int sz1 = a.ss-a.ff+1;
        int sz2 = b.ss-b.ff+1;
        if(sz1==sz2){
            return a.ff>b.ff;
        }
        return sz1<sz2;
    }
};

int32_t main(){
    get_it_done();
    int tc=1;
    cin >> tc;
    while (tc--){
        int n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        vi a(n+1);
        priority_queue<pii,vpii,cmp> pq;
        pq.push(mp(1,n));
        int i = 0;
        while(pq.size()){
            ++i;
            auto x = pq.top();
            pq.pop();
            if((x.ss-x.ff+1)&1){
                int idx = (x.ff+x.ss)/2;
                a[idx] = i;
                if(x.ff<idx){
                    pq.push(mp(x.ff,idx-1));
                }
                if(idx<x.ss){
                    pq.push(mp(idx+1,x.ss));
                }
            }else{
                int idx = (x.ff+x.ss-1)/2;
                a[idx] = i;
                if(x.ff<idx){
                    pq.push(mp(x.ff,idx-1));
                }
                if(idx<x.ss){
                    pq.push(mp(idx+1,x.ss));
                }
            }
        }
        loop(i,1,n+1){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
