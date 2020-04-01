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
    // cin >> q;
    while (q--){
        int n,k;
        cin>>n>>k;
        vi a(n);
        loop(i,0,n) cin>>a[i];
        unordered_map<int,int> mk;
        int temp = k;
        for(int i=2;i*i<=k;i++){
            if(!(temp%i)){
                while(!(temp%i)){
                    temp /= i;
                    mk[i]++;
                }
            }
        }
        // If k is a prime
        if(temp!=1) mk[temp] += 1;
        unordered_map<int,int> m1;
        int cnt = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            int temp = a[j];
            for(int z=2;z*z<=temp;z++){
                if(!(temp%z)){
                    while(!(temp%z)){
                        temp /= z;
                        m1[z]++;
                    }
                }
            }
            if(temp!=1) m1[temp]++;
            while(i<=j){
                bool flag = 0;
                for(auto x:mk){
                    if(m1[x.ff]<mk[x.ff]) flag = 1;
                }
                if(flag) break;
                cnt += (n-j);
                int temp = a[i];
                for(int z=2;z*z<=temp;z++){
                    if(!(temp%z)){
                        while(!(temp%z)){
                            temp /= z;
                            m1[z]--;
                        }
                    }
                }
                if(temp!=1) m1[temp]--;
                i++;
            }
            j++;
        }
        cout<<cnt<<endl;

        
    }
}
