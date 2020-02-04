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

int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int mini = LLONG_MAX;
        int a = -1;
        int b = -1;
        int arr[s.size() + 1ll][2];
        arr[0][0] = 0;
        arr[0][1] = 0;
        map<pair<int,int>, int> m;
        m[mp(0,0)] = 0;
        loop(i,1,n+1){
            if (s[i - 1] == 'L')
            {
                arr[i][0] = arr[i - 1][0];
                arr[i][1] = arr[i - 1][1] - 1;
            }
            if (s[i - 1] == 'R')
            {
                arr[i][0] = arr[i - 1][0];
                arr[i][1] = arr[i - 1][1] + 1;
            }
            if (s[i - 1] == 'U')
            {
                arr[i][0] = arr[i - 1][0] + 1;
                arr[i][1] = arr[i - 1][1];
            }
            if (s[i - 1] == 'D')
            {
                arr[i][0] = arr[i - 1][0] - 1;
                arr[i][1] = arr[i - 1][1];
            }
            if (m.count(mp(arr[i][0], arr[i][1]))){
                auto j = m[mp(arr[i][0], arr[i][1])];
                if (i - j < mini){
                    mini = i - j - 1;
                    a = j + 1;
                    b = i;
                }
            }
            m[mp(arr[i][0], arr[i][1])] = i;
        }
        if (a == -1){
            cout << -1 << endl;
        }
        else{
            cout << a << " " << b << endl;
        }
    }
}
