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
#define mci map<char,int>  
#define pii pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18
#define sp(x,y) fixed<<setprecision(y)<<x

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
void swap(int &a,int &b){
	a^=b;b^=a;a^=b;
}
const int N = 1e5+5;
int dp[N];
bool mat[2][N];


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        int n,q;
        cin>>n>>q;
        int cnt = 0;
        while(q--){
            int r,c;
            cin>>r>>c;
            r -= 1;
            c -= 1;
            int flag=0;
            mat[r][c] = 1-mat[r][c];
            if(mat[r][c] == 1) flag+=1;
            else flag -= 1;
            if(c-1>=0 && mat[1-r][c-1])
                cnt += flag;
            if(mat[1-r][c])
                cnt += flag;
            if(c+1<n && mat[1-r][c+1]) 
                cnt += flag;
            if(mat[1][n-1]==0 && mat[0][0]==0 && cnt==0){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }

        }
    }
}
