#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
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
const int N = 2e5+5;
int dp[N];
string s;
int dist[10][10];

int solve(int x,int y){
    // Using Floyd Warshall
    loop(i,0,10)
        loop(j,0,10)
            dist[i][j]=inf;
 
    loop(i,0,10)
        dist[i][(i+x)%10]=dist[i][(i+y)%10]=1;
 
    loop(i,0,10){
        loop(j,0,10){
            loop(k,0,10)
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
        }
    }
 
    int ans=0;
    loop(i,1,s.length()){
        int val=s[i]-'0';
        int val2=s[i-1]-'0';
 
        if(dist[val2][val]==1e18)
            return -1;
        ans += (dist[val2][val]-1);
    }
    return ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>s;
        loop(i,0,10){
            loop(j,0,10){
                cout<<solve(i,j)<<" ";
                // break;
            }
            cout<<endl;
        }

    }
}
