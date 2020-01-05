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
const int N = 1e6+5;
int dp[N];
vi adjList[N];

// int calc(int n){
//     // n => No of triplets
//     dp[0] = 0;
//     dp[1] = 0;
//     dp[2] = 0;
//     dp[3] = 1;
//     loop(i,4,n+1){
//         dp[i] = dp[i-1]+(i-2);
//     }
//     return dp[n];
// }

string solve(string &a,string &b,int k){
    string str;
    loop(i,0,k){
        if(a[i]==b[i])
            str.pb(a[i]);
        else if((a[i]=='S' && b[i]=='E') || (a[i]=='E' && b[i]=='S'))
            str.pb('T');
        else if((a[i]=='S' && b[i]=='T') || (a[i]=='T' && b[i]=='S'))
            str.pb('E');
    else if((a[i]=='E' && b[i]=='T') || (a[i]=='T' && b[i]=='E'))
            str.pb('S');
    }
    return str;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        int n,k;
        cin>>n>>k;
        vector<string> a(n);
        loop(i,0,n) cin>>a[i];
        if(n<3){
            cout<<0<<endl;
            continue;
        }
            set<string> s;
            for(auto x:a){
                s.insert(x);
            }
            int cnt = 0;
            loop(i,0,n){
                loop(j,i+1,n){
                    string temp = solve(a[i],a[j],k);
                    if(s.find(temp)!=s.end()){
                        cnt++;
                    }
                }
            }
            cout<<cnt/3<<endl;

    }
}
