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
const int N = 1e5+5;
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        int n,x;
        cin>>n>>x;
        string s;
        cin>>s;
        // if(x<0){
        //     int diff = 0;
        //     loop(i,0,n){
        //         if(s[i]=='1') diff++;
        //         else diff--;
        //     }
        //     x *= (-1);
        //     int rep = x/diff;
        //     string z="";
        //     rep += 1;
        //     while(rep--) z += s;
        //     diff=0;
        //     int cnt = 0;
        //     loop(i,0,z.size()){
        //         if(s[i]=='1') diff++;
        //         else diff--;
        //         if(diff==x){
        //             cnt++;
        //         }
        //     }
        //     cout<<cnt<<endl;

        // }else if(x>0){
        //     int diff = 0;
        //     loop(i,0,n){
        //         if(s[i]=='0') diff++;
        //         else diff--;
        //     }
        //     if(diff<0){
        //         cout<<0<<endl;
        //     }
        //     int rep = x/diff;
        //     string z="";
        //     rep += 1;
        //     while(rep--) z += s;
        //     diff=0;
        //     int cnt = 0;
        //     loop(i,0,z.size()){
        //         if(s[i]=='0') diff++;
        //         else diff--;
        //         if(diff==x){
        //             cnt++;
        //         }
        //     }
        //     cout<<cnt<<endl;
        // }else{
        //     if(n==1){
        //         cout<<1<<endl;
        //     }else{
        //         int diff = 0;
        //         loop(i,0,n){
        //             if(s[i]=='1') diff++;
        //             else diff--;
        //         }
        //         if(diff==0) cout<<-1<<endl;
        //         else cout<<1<<endl;
        //     }
        // }
        int diff[N]={};
        if(s[0]=='0'){
            diff[0] = 1;
        }else{
            diff[0] = -1;
        }
        map<int,int> m;
        loop(i,1,n){
            diff[i] = diff[i-1];
            if(s[i]=='1'){
                diff[i] -= 1;
            }else{
                diff[i] += 1;
            }
            m[diff[i]]++;
        }
        if(diff[n-1]==0){
            if(m[x]){
                cout<<-1<<endl;
            }else{
                cout<<0<<endl;
            }
            continue;
        }
        


    }
}
