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
        int n,m;
        cin>>n>>m;
        vector<string> a;
        bool flag = true;
        string s1 = "";
        string s2 = "";
        loop(i,0,m){
            if(flag){
                s1+='B';
                s2+='W';
                flag = 0;
            }
            else{
                s1 += 'W';
                s2 += 'B';
                flag = 1;
            }
        }
        loop(i,0,n){
            if(i%2==0){
                a.pb(s1);
            }
            else{
                a.pb(s2);
            }
        }
        if((n*m)%2==0){
            if(a[n-1][m-1] == 'W'){
                a[n-1][m-1] = 'B';
            }
            else{
                a[n-1][m-2] = 'B';
            }
        }
        loop(i,0,n){
            cout<<a[i]<<endl;
        }

        
    }
}
