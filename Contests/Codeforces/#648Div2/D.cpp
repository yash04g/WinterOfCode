#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
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
char a[55][55];
bool visited[55][55];
int n,m;
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool possible(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m){
        return 0;
    }
    return 1;
}

void dfs(int x,int y){
    if(a[x][y]=='B' || a[x][y]=='#'){
        return;
    }
    visited[x][y] = 1;
    loop(i,0,4){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(possible(nx,ny) && !visited[nx][ny]){
            dfs(nx,ny);
        }
    }
}

void solve(){
    cin>>n>>m;
    loop(i,0,n) loop(j,0,m) cin>>a[i][j];
    int cnt = 0;
    loop(i,0,n){
        loop(j,0,m){
            if(a[i][j]=='G'){
                cnt++;
            }
        }
    }
    if(cnt==0){
        cout<<"Yes"<<endl;
        return;
    }
    loop(i,0,n){
        loop(j,0,m){
            if(a[i][j]=='B'){
                loop(k,0,4){
                    int nx = i+dir[k][0];
                    int ny = j+dir[k][1];
                    if(possible(nx,ny) && a[nx][ny]!='B'){
                        a[nx][ny] = '#';
                    }
                }
            }
        }
    }
    loop(i,0,n){
        loop(j,0,m){
            if(a[i][j]=='G') cnt--;
        }
    }
    if(cnt>0){
        cout<<"No"<<endl;
        return;
    }
    bool flag = 1;
    mset(visited,0);
    dfs(n-1,m-1);
    loop(i,0,n){
        loop(j,0,m){
            if(a[i][j]=='G' && !visited[i][j]){
                flag = 0;
                break;
            }
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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
