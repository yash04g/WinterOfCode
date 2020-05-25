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

void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    bool flag = 0;
    if(n>m){
        swap(n,m);
        swap(a,b);
        flag = 1;
    }
    int arr[n+1][m+1];
    mset(arr,0);
    if(n==a && m==b){
        cout<<"YES"<<endl;
        if(flag){
            loop(j,0,m){
                loop(i,0,n){
                    cout<<1;
                }
                cout<<endl;
            }
        }else{
            loop(i,0,n){
                loop(j,0,m){
                    cout<<1;
                }
                cout<<endl;
            }
        }
        return;
    }
    loop(i,0,n){
        int cnt = b;
        loop(j,0,m){
            if((i&1) && j&1 && cnt){
                arr[i][j] = 1;
                cnt--;
            }else if((i&1) && !(j&1) && cnt){
                arr[i][j] = 1;
                cnt--;
            }
        }
    }
    loop(j,0,m){
        int cnt = 0;
        loop(i,0,n){
            if(arr[i][j]==1) cnt++;
        }
        if(cnt>a || cnt<a){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    if(flag){
        loop(j,0,m){
            loop(i,0,n){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }else{
        loop(i,0,n){
            loop(j,0,m){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }



}

int32_t main(){
    get_it_done();
    int tc=1;
    cin >> tc;
    while (tc--){
        solve();        
    }
}
