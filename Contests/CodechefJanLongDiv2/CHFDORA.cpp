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
const int N = 1e4+5;
int dp[N];
int n,m;



int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        cin>>n>>m;
        int **a = new int*[n+1];
        loop(i,0,n+1){
            a[i] = new int[m+1];
        }
        loop(i,0,n) loop(j,0,m) cin>>a[i][j];
        
        int res = n*m;
        int len = min(n,m);
        if(!(len&1)) len--;
        for(int sz = 3; sz<= len; sz += 2){
            for(int i = sz/2; i < n-sz/2; i++){
                for(int j = sz/2; j < m-sz/2; j++){
                    bool flag = true;
                    loop(k,1,(sz/2)+1){
                        if(a[i-k][j] != a[i+k][j]){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        continue;
                    }
                    flag = true;
                    loop(k,1,(sz/2)+1){
                        if(a[i][j-k] != a[i][j+k]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        res+=1;
                    }
                }
            }
        }
        cout<<res<<endl;   	

    }
}
