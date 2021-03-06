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
    int q=1;
    cin >> q;
    while (q--){
        int n;
        cin>>n;
        vi a(n);
        map<int,int> m;
        loop(i,0,n){
            cin>>a[i];
        }
        loop(i,0,n){
            m[a[i]] = i+1;
        }
        bool visited[n+1];
        mset(visited,0);
        int last = n;
        int idx = -1;
        bool flag = true;
        loop(i,1,n+1){
            if(m[i]==last && (idx==-1 || idx==last)){
                visited[m[i]] = true;
                while(visited[last]){
                    last--;
                }
                idx = -1;
            }
            else{
                if(idx==-1){
                    idx = m[i]+1;
                    visited[m[i]] = true;
                }
                else if(m[i]==idx){
                    idx = idx+1;
                    visited[m[i]] = true;
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

    }
}
