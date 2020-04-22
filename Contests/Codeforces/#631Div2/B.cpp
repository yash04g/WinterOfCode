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
        int maxi = 1;
        int mini = inf;
        map<int,int> m;
        loop(i,0,n) cin>>a[i],maxi = max(maxi,a[i]),mini = min(mini,a[i]),m[a[i]]++;
        bool flag = 1;
        bool flag1 = 1;
        for(auto x:m){
            if(x.ss==1 && flag){
                flag = 0;
            }else if(x.ss==1){
                continue;
            }else{
                if(!flag) flag1 = 0;
                else if(x.ss>2) flag1 = 0;
            }
        }
        if(maxi==mini && m[1]==2){
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
            continue;
        }
        if(m[mini]==1 || maxi==mini || n<=maxi || !flag1){
            cout<<0<<endl;
            continue;
        }
        // We need to find max len such that (1,maxi) is covered and its length is maxi
        // Ans i 0,1,2
        int len1 = 0;
        flag = 1;
        set<int> s;
        int idx = 0;
        loop(i,0,n){
            if(s.find(a[i])!=s.end()){
                flag = 0;
                break;
            }else{
                s.insert(a[i]);
                len1++;
            }
            if(len1==maxi) {
                idx = i+1;
                break;
            }
        }
        vpii ans;
        if(flag){
            int len2 = 0;
            loop(i,idx,n){
                len2++;
            }
            if(len2!=(n-len1)){
                flag = 0;
            }
            if(flag){
                ans.pb(mp(len1,len2));
            }
        }
        reverse(all(a));
        len1 = 0;
        flag = 1;
        s.clear();
        idx = 0;
        loop(i,0,n){
            if(s.find(a[i])!=s.end()){
                flag = 0;
                break;
            }else{
                s.insert(a[i]);
                len1++;
            }
            if(len1==maxi) {
                idx = i+1;
                break;
            }
        }
        if(flag){
            int len2 = 0;
            loop(i,idx,n){
                len2++;
            }
            if(len2!=(n-len1)){
                flag = 0;
            }
            if(flag){
                ans.pb(mp(len2,len1));
            }
        }
        if(ans.size()==0){
            cout<<0<<endl;
            continue;
        }
        set<int> s2;
        loop(i,0,ans.size()){
            s2.insert(ans[i].ff);
            s2.insert(ans[i].ss);
        }
        if(s2.size()==1){
            cout<<1<<endl;
            cout<<ans[0].ff<<" "<<ans[0].ss<<endl;
        }else{
            cout<<ans.size()<<endl;
            loop(i,0,ans.size()){
                cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
            }
        }

        
    }
}
