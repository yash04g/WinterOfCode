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

int day(int y){  
    int d = 1;
    int m = 2;
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  y / 400 + t[m - 1] + d) % 7;  
}  


int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        int m1,y1,m2,y2;
        cin>>m1>>y1>>m2>>y2;
        int cnt = 0;
        if(m1>2){
            y1++;
        }
        if(m2<2){
            y2--;
        }
        loop(i,y1,y2+1){
            if(i%4 == 0 && (i!=100 || i!=200 || i!=300)){
                if(day(i) == 6){
                    cnt++;
                }
            }
            else{
                if(day(i) == 6 || day(i) == 0){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}