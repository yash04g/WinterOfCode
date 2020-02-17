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
const int N = 1e3+5;
int n,p;
int a[N];
int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        cin>>n>>p;
        loop(i,0,n) cin>>a[i];
        int cnt = 0;
        bool flag = 1;
        loop(i,0,n-1){
            if(p%a[i]==0){
                cnt++;
            }
            if(a[i+1]%a[i]){
                flag = 0;
            }
        }
        if(p%a[n-1]==0) cnt++;
        // deb(cnt);
        if(flag && cnt==n){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES ";
            if(cnt==n){
            vi ans(n,0);
            int req = p+a[0]-1;
            int sum = 0;
            int k = n-1;
            int left = p;
            while(1){
                if(k<0){
                    break;
                }
                int cnt = 0;
                if(left>=a[k] && left%a[k]==0){
                    cnt = (left/a[k]) - 1;
                    left -= a[k]*cnt;
                }else{
                    if(left<=0){
                        break;
                    }
                    else if(left<a[k]){
                        k--;
                        continue;
                    }else{
                        cnt = (left/a[k])+1;
                        left -= a[k]*cnt;
                    }
                }
                ans[k] = cnt;
                k -= 1;
            }
            loop(i,0,n) cout<<ans[i]<<" ";
            cout<<endl;
            }else{
                vi ans(n,0);
                loop(i,0,n){
                    if(p%a[i]==0){
                        continue;
                    }else{
                        ans[i] = (p/a[i])+1;
                        break;
                    }
                }
                loop(i,0,n){
                    cout<<ans[i]<<" ";
                }
            }
        }
    }
}

