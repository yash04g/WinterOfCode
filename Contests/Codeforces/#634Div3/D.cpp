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
        string s[9];
        loop(i,0,9) cin>>s[i];
        int arr[10][10];
        loop(i,0,9){
            loop(j,0,9){
                arr[i+1][j+1] = (s[i][j]-'0');
            }
        }

        arr[1][1] = arr[1][2];
        arr[2][4] = arr[2][5];
        arr[3][7] = arr[3][8];
        arr[4][2] = arr[4][3];
        arr[5][5] = arr[5][6];
        arr[6][8] = arr[6][9];
        arr[7][3] = arr[7][1];
        arr[8][6] = arr[8][4];
        arr[9][9] = arr[9][7];

        loop(i,1,10)
        {
            loop(j,1,10)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        
    }
}
