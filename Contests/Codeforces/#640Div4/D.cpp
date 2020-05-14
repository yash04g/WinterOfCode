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
    int tc=1;
    cin >> tc;
    while (tc--){
        int n;
        cin>>n;
        vi a(n);
        loop(i,0,n){
            cin>>a[i];
        }
        if(n==1){
            cout<<1<<" "<<a[0]<<" "<<0<<endl;
            continue;
        }
        int i = 0;
        int j = n-1;
        int cnt1 = 0;
        int cnt2 = 0;
        int prev1=0,prev2=0;
        bool flag = 1;
        int moves = 0;
        while(i<=j){
            if(flag){
                moves++;
                prev1 = 0;
                while(prev1<=prev2 && i<=j){
                    prev1 += a[i];
                    cnt1 += a[i];
                    i++;
                }
                flag = 0;
            }else{
                moves++;
                prev2 = 0;
                while(prev2<=prev1 && j>=i){
                    prev2 += a[j];
                    cnt2 += a[j];
                    j--;
                }
                flag = 1;
            }
            // deb(prev1,prev2,cnt1,cnt2,i,j);
        }
        cout<<moves<<" "<<cnt1<<" "<<cnt2<<endl;
    }
}
