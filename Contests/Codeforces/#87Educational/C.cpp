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
const double pi = 3.141592653589;

int32_t main(){
    get_it_done();
    int tc=1;
    cin >> tc;
    while (tc--){
        long double n;
        cin>>n;
        n *= 2;
        long double angle = (n-2)*180.0/n;
        long double org = angle;
        angle -= 90;
        long double ans = 0;
        long double temp = 0;
        double angle1 = angle;
        int val = n/4;
        if(((int)n)%4) val++;
        loop(i,0,n/4-1){
            // deb(angle);
            angle *= 3.141592653/180;
            temp += abs(sin(angle));
            int na = (90-angle1);
            angle1 = org-90-na;
            angle = angle1;
        }
        ans += 1;
        ans += 2*temp;
        cout<<fixed<<setprecision(10)<<ans<<endl;

    }
}
